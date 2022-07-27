#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>

#include "global_state.h"
#include "drivers/Accelerometer.h"

#include "./AppComponent.hpp"

#include "oatpp/network/Server.hpp"
#include "api/controller/CamAPIController.hpp"
#include "api/controller/MotorController.hpp"
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
  oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                components.serverConnectionHandler.getObject());
  server.run();
}

int main() {
    Accelerometer* robot_accelerometer = new Accelerometer();

    robot_accelerometer->begin_update_on_interval(100);

    oatpp::base::Environment::init();
    run_server();
    oatpp::base::Environment::destroy();
    return 0;
}