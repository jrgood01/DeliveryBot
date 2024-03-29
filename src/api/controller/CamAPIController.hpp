/*
    This file is taken from oatpp yuv websocket stream example programs and has been modified for our use
    The oriingal file is licensed under the Apache License, Version 2.0
    See the original at: https://github.com/oatpp/example-yuv-websocket-stream/blob/master/src/controller/CamAPIController.hpp
*/

#ifndef CONTROLLER_CAMAPICONTROLLER_HPP_
#define CONTROLLER_CAMAPICONTROLLER_HPP_

#include "api/dto/DTOs.hpp"

#include "oatpp-websocket/Handshaker.hpp"
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

#include "api/video_stream_backend/ImageWSListener.hpp"
#include "api/video_stream_backend/V4LGrabber.hpp"

/**
 * Sample Api Controller.
 */

namespace apiv0 {


class CamAPIController : public oatpp::web::server::api::ApiController {
 public:
  /**
   * Constructor with object mapper.
   * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
   */
  CamAPIController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
  : oatpp::web::server::api::ApiController(objectMapper, "/v0/cam"), m_v4linit(false) {}
  ~CamAPIController();

  static std::shared_ptr<CamAPIController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                                                                         objectMapper)) {
    return std::make_shared<CamAPIController>(objectMapper);
  }

  int v4lInit();
  int v4lDeinit();

#include OATPP_CODEGEN_BEGIN(ApiController)

  ENDPOINT_INFO(ws) {
    info->summary = "Websocket-Handshake-Path";
  }
  ENDPOINT("GET", "/stream/ws", ws, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
    if(!m_v4linit) {
      v4lInit();
    }
    return oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(), m_imagewsConnectionHandler);
  };
  ADD_CORS(ws, "*", "GET, OPTIONS");

  ENDPOINT_INFO(stream) {
    info->summary = "Demo page how to consume the stream in Javascript";
  }
  ENDPOINT("GET", "/stream", stream);
  ADD_CORS(stream, "*", "GET, OPTIONS");

  ENDPOINT_INFO(streamres) {
    info->summary = "Endpoint to receive webpages resources";
  }
  ENDPOINT("GET", "/stream/{filename}", streamres, PATH(String, filename));
  ADD_CORS(streamres, "*", "GET, OPTIONS");




#include OATPP_CODEGEN_END(ApiController)

 private:
  static const char* TAGCam;

  const char * basename (const char *filename);
  static void handle_frame(void* data, const void* image, int size);

  std::shared_ptr<oatpp::websocket::ConnectionHandler> m_imagewsConnectionHandler;
  std::shared_ptr<ImageWSRegistry> m_imageReceivers;
  std::shared_ptr<V4LGrabber> m_grabber;
  std::atomic_bool m_v4linit;
};

}

#endif //CONTROLLER_CAMAPICONTROLLER_HPP_