#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>
#include <ifaddr>

#include "global_state.h"
#include "drivers/Accelerometer.h"
#include "drivers/Camera.h"

#include "./controller/CamAPIController.hpp"
#include "./AppComponent.hpp"

#include "oatpp-swagger/Controller.hpp"
#include "oatpp/network/Server.hpp"

//Boilerplate method from oatpp
void run_server() {
  AppComponent components; 
  auto router = components.httpRouter.getObject();
  
  oatpp::web::server::api::Endpoints docEndpoints;
  docEndpoints.append(router->addController(apiv0::CamAPIController::createShared())->getEndpoints());
  router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
  oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                components.serverConnectionHandler.getObject());
  server.run();
}

int main() {
    Accelerometer* robot_accelerometer = new Accelerometer();
    Camera* robot_camera = new Camera();
    robot_accelerometer->begin_update_on_interval(100);
    robot_camera->begin_update_camera();
    oatpp::base::Environment::init();
    run_server();
    oatpp::base::Environment::destroy();
    return 0;
}