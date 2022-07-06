#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>

#include "drivers/Accelerometer.hpp"
#include "global_state.hpp"

#include "include/oatpp/web/server/HttpConnectionHandler.hpp"
#include "include/oatpp/network/Server.hpp"
#include "include/oatpp/network/tcp/server/ConnectionProvider.hpp"

int main() {
    robot_accelerometer = accelerometer();
}