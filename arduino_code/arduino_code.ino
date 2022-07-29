const int L_BACK = 11;
const int L_FORWARD = 10;
const int R_BACK = 9;
const int R_FORWARD = 6;
enum Transmission_State {
  START,
  SET_POWER_1,
  SET_POWER_2,
  TOGGLE_1,
  TELEM_1,
  TELEM_2,
  TELEM_3
};

Transmission_State state;
bool is_manual = true;

int power_L_buffer = 0;
int power_R_buffer = 0;
int power_buffer_ready = false;

int center_echoPin = 3;
int center_trigPin = 4;
int left_echoPin = A0;
int left_trigPin = 5;
int right_echoPin = 8;
int right_trigPin = A9;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A8, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(A8, HIGH);
  digitalWrite(12, HIGH);
  Serial.begin(9600);
  for (int i = 6; i <= 52; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(center_trigPin, OUTPUT);
  pinMode(center_echoPin, INPUT);
  pinMode(left_trigPin, OUTPUT);
  pinMode(left_echoPin, INPUT);
  pinMode(right_trigPin, OUTPUT);
  pinMode(right_echoPin, INPUT);
}

void setFLPower(int power, bool forwards) {
  analogWrite(9, power);
  digitalWrite(22, forwards ? HIGH : LOW);
  digitalWrite(23, forwards ? LOW : HIGH);
}

void setBLPower(int power, bool forwards) {
  analogWrite(6, power);
  digitalWrite(24, forwards ? HIGH : LOW);
  digitalWrite(25, forwards ? LOW : HIGH);
}

void setFRPower(int power, bool forwards) {
  analogWrite(11, power);
  digitalWrite(26, forwards ? HIGH : LOW);
  digitalWrite(27, forwards ? LOW : HIGH);
}

void setBRPower(int power, bool forwards) {
  analogWrite(10, power);
  digitalWrite(36, forwards ? LOW : HIGH);
  digitalWrite(37, forwards ? HIGH : LOW);
}

void straight(int power, bool forwards) {
  setBRPower(power, forwards);
  setFRPower(power, forwards);
  setBLPower(power, forwards);
  setFLPower(power, forwards);
}

void apply_power(int powerL, int powerR) {
  setBRPower(abs(powerR), powerR > 0);
  setFRPower(abs(powerR), powerR > 0);
  setBLPower(abs(powerL), powerL > 0);
  setFLPower(abs(powerL), powerL > 0);
}

void motor_break() {
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

float distance(int sensor) {
  int trigPin = 0;
  int echoPin = 0;
  if (sensor == 0) {
    trigPin = center_trigPin;
    echoPin = center_echoPin;
  } else if (sensor == -1) {
    trigPin = left_trigPin;
    echoPin = left_echoPin;
  } else if (sensor == 1) {
    trigPin = right_trigPin;
    echoPin = right_echoPin;
  }
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration_us = pulseIn(echoPin, HIGH);
  float distance_cm = 0.017 * duration_us;
  return distance_cm;
}

void apply_state_transition(int input) {
  if (input == 10)
    return;
  if (state == START) {
    if (input == 'A' && is_manual) {
      state = SET_POWER_1;
    } else if (input == 'C') {
      apply_power(0, 0);
    } else if (input == 'B') {
      state = TOGGLE_1;
    } else if (input == 'T') {
      Serial.flush();
      
      Serial.print(distance(-1));
      Serial.print(':');
      Serial.print(distance(0));
      Serial.print(':');
      Serial.print(distance(1));
    }
  } else if (state == SET_POWER_1) {
    if (input != -1) {
      power_L_buffer = input;
      state = SET_POWER_2;
    }
  } else if(state == SET_POWER_2) {
    if (input != -1) {
      power_R_buffer = input;
      power_buffer_ready = true;
      state = START;
    }
  }else if(state == TOGGLE_1) {
    if (is_manual)
      Serial.write('T');
    else {
      apply_power(0, 0);
      Serial.write('F');
    }
    is_manual = !is_manual;
    state = START;
  }
}

void loop() {
  int serial_dat = -1;
  if (power_buffer_ready) {
    apply_power(map(power_L_buffer, 0, 255, -255, 255), map(power_R_buffer, 0, 255, -255, 255));
    power_buffer_ready = false;
  }
  
  if (Serial.available())
  {
    serial_dat = Serial.read();
    Serial.flush();
  }
    
  apply_state_transition(serial_dat);

  if (!is_manual) {
    autonomous_loop();
  }
}

//don't go over 150 for power
//if starts going really quick

bool sweepDir = false;
int left = 130;
int right = 255;

void sweep_left() {
  left = 120;
  right = 255;
}

void sweep_right() {
  left = 255;
  right = 120;
}

int cycles = 0;
int L_POWER = 200;
int R_POWER = 200;
void autonomous_loop() {  
  int lDistance = distance(-1);
  int rDistance = distance(1);
  int cDistance = distance(0);
  if (cDistance < 30 || rDistance < 30 || lDistance < 30) {
    apply_power(-255, -255);
    delay(1000);
    if (rDistance < lDistance){
      apply_power(255, -255);
      delay(2000);
    } else {
      apply_power(-255, 255);
      delay(2000);
    }
  }
  if (lDistance < rDistance && lDistance < 100) {
    apply_power(255, 150);
  } else if (rDistance > lDistance && rDistance < 100) {
    apply_power(150, 255);
  } else {
    apply_power(200, 200);
  }
  Serial.print(lDistance);
  Serial.print(":");
  Serial.print(cDistance);
  Serial.print(":");
  Serial.println(rDistance);
}
