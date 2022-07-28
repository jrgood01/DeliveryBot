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

int echoPin = 3;
int trigPin = 4;
void setup() {
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  Serial.begin(9600);
  for (int i = 6; i <= 52; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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

float distance() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration_us = pulseIn(echoPin, HIGH);
  float distance_cm = 0.017 * duration_us;
  return distance_cm;
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
  right = 50;
}

int cycles = 0;
void autonomous_loop() {
  Serial.println((distance()));
  Serial.println();
  if (distance() < 30) {
    apply_power(-255, -255);
    delay(1000);
    sweepDir = !sweepDir;
  }
  Serial.println(cycles);
  if(sweepDir)
    sweep_left();
   else
    sweep_right();

   if (cycles > 300) {
    sweepDir = !sweepDir;
    cycles = 0;
   }
   apply_power(left, right);
   cycles +=1;
}
