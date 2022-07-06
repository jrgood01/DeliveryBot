#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>

#include "global_state.h"
#include "drivers/Accelerometer.h"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

int main() {
    Accelerometer* robot_accelerometer = new Accelerometer();
    run_server();
}

//Boilerplate form oatpp
void run_server() {
    /* Create Router for HTTP requests routing */
    auto router = oatpp::web::server::HttpRouter::createShared();

    /* Create HTTP connection handler with router */
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    /* Create TCP connection provider */
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared(
            {"localhost", 8000, oatpp::network::Address::IP_4});

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Print info about server port */
    OATPP_LOGI("Robot control server", "Server running on port %s", connectionProvider->getProperty("port").getData());

    /* Run server */
    server.run();
}