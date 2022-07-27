/*
    This file is taken from oatpp yuv websocket stream example program
    The oriingal file is licensed under the Apache License, Version 2.0
    See the original at: https://github.com/oatpp/example-yuv-websocket-stream/blob/master/src/backend/Utils.hpp
*/

#ifndef SRC_BACKEND_UTILS_HPP
#define SRC_BACKEND_UTILS_HPP

#include <oatpp/core/Types.hpp>

class Utils {
 public:
  static oatpp::String getExtension(const oatpp::String& filename);
  static oatpp::String guessMimeType(const oatpp::String& filename);
};

#endif //SRC_BACKEND_UTILS_HPP