#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include <CppLinuxSerial/SerialPort.hpp>
#include <string>
#include <iostream>
#include <pthread.h>
#include "../../global_state.hpp"

using namespace mn::CppLinuxSerial;
using namespace std;
namespace apiv0 {

  class MotorController : public oatpp::web::server::HttpRequestHandler {
  public:
    int convert(std::string input) {
      char* hex = (char*) malloc(sizeof(char) * 5);
      int val = stoi(input);
      val = (val / 2);
      val += 128;
      sprintf(hex, "%x", abs(val));
      return val;
    }

    /**
    * Handle incoming request and return outgoing response.
    */
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
      pthread_mutex_lock(&port_lock);
      auto tail = request->getPathTail();
      auto queryParams = oatpp::network::Url::Parser::parseQueryParams(tail);
      auto L_POWER = queryParams.get("L_POWER");
      auto R_POWER = queryParams.get("R_POWER");

      uint8_t l_power_val = convert(L_POWER);
      uint8_t r_power_val = convert(R_POWER);
 
      vector<uint8_t> data_vector;
      data_vector.push_back('A');
      data_vector.push_back(l_power_val);
      data_vector.push_back(r_power_val);
      // Write some ASCII data
      serialPort.WriteBinary(data_vector);
      pthread_mutex_unlock(&port_lock);

      return ResponseFactory::createResponse(Status::CODE_200,"OK");
    }

  };
      /*ENDPOINT("POST", "/sendCommand", root, BODY_STRING(String, command)) {
        system("echo -e 'A" + command + " > /dev/ttyACM0");
        return createResponse(Status::CODE_200, "OK");
      }
    }
  }
  */
}