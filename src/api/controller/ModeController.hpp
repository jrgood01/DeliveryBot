#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../../global_state.hpp"
#include <CppLinuxSerial/SerialPort.hpp>
#include <string>
#include <iostream>
#include <pthread.h>

using namespace mn::CppLinuxSerial;
using namespace std;
namespace apiv0 {

  class ModeController : public oatpp::web::server::HttpRequestHandler {
  public:
    /**
    * Handle incoming request and return outgoing response.
    */
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
      pthread_mutex_lock(&port_lock);
      vector<uint8_t> data_vector;
      data_vector.push_back('B');
      // Write some ASCII data
      serialPort.WriteBinary(data_vector);
      pthread_mutex_unlock(&port_lock);
      return ResponseFactory::createResponse(Status::CODE_200,"OK");
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