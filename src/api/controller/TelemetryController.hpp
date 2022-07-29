/*
 * This file contains endpoints for telemetry aqcuisition
 */
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include <CppLinuxSerial/SerialPort.hpp>
#include <string>
#include <iostream>
#include "../../global_state.hpp"
#include <pthread.h>

using namespace mn::CppLinuxSerial;
using namespace std;
namespace apiv0 {

  class TelemetryController: public oatpp::web::server::HttpRequestHandler {
  public:
    std::string getSensor(unsigned char sensor, SerialPort serialPort) {
        vector<uint8_t> data_vector;
        data_vector.push_back('D');
        data_vector.push_back((uint8_t)sensor);
        serialPort.WriteBinary(data_vector);
        std::string sensor_data;
	      serialPort.Read(sensor_data);
        //Send acknowledge byte
        vector<uint8_t> ack_vector;
        ack_vector.push_back('K');
        serialPort.WriteBinary(ack_vector);
        return sensor_data;
    }
    /**
    * Handle incoming request and return outgoing response.
    */
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
      pthread_mutex_lock(&port_lock);
        vector<uint8_t> data_vector;
        data_vector.push_back('T');
        serialPort.WriteBinary(data_vector);
        std::string sensor_data;
	      serialPort.Read(sensor_data);
        
      pthread_mutex_unlock(&port_lock);
      return ResponseFactory::createResponse(Status::CODE_200,sensor_data);
    }
    }   ;
      /*ENDPOINT("POST", "/sendCommand", root, BODY_STRING(String, command)) {
        system("echo -e 'A" + command + " > /dev/ttyACM0");
        return createResponse(Status::CODE_200, "OK");
      }
    }
  }
  */
}