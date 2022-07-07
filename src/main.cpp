#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>

#include "global_state.h"
#include "drivers/Accelerometer.h"
#include "drivers/Camera.h"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "api/controller/StaticContent.hpp"

//Boilerplate form oatpp
void run_server() {
    /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();

    /* Route GET - "/hello" requests to Handler */
    router->route("GET", "/home", std::make_shared<StaticContentController>());

    /* Create HTTP connection handler with router */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    /* Create TCP connection provider */
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared(
            {"192.168.7.190", 8000, oatpp::network::Address::IP_4});

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Priny info about server port */
    OATPP_LOGI("Robot Control", "Server running on port %s", connectionProvider->getProperty("port").getData());

    /* Run server */
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