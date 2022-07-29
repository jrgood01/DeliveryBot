#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>

#include "global_state.hpp"

#include "./AppComponent.hpp"

#include "oatpp/network/Server.hpp"

#include "api/controller/CamAPIController.hpp"
#include "api/controller/MotorController.hpp"
#include "api/controller/ModeController.hpp"
#include "api/controller/TelemetryController.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

//Boilerplate method from oatpp
void run_server() {
  AppComponent components; 
  auto router = components.httpRouter.getObject();
  
  oatpp::web::server::api::Endpoints docEndpoints;
  docEndpoints.append(router->addController(apiv0::CamAPIController::createShared())->getEndpoints());
  router->route("GET", "/control", std::make_shared<apiv0::MotorController>());
  router->route("GET", "/controlMode", std::make_shared<apiv0::ModeController>());
  router->route("GET", "/telemetry", std::make_shared<apiv0::TelemetryController>());
  oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                components.serverConnectionHandler.getObject());
  server.run();
}

int main() {
      SerialPort port("/dev/ttyACM0", BaudRate::B_9600, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
      serialPort = port;
      serialPort.SetTimeout(-1); 
      serialPort.Open();
    oatpp::base::Environment::init();
    run_server();
    oatpp::base::Environment::destroy();
    return 0;
}