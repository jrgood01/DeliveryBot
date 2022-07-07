#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

class StaticContentController : public oatpp::web::server::HttpRequestHandler {
public:

    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
        oatpp::String response_str = oatpp::String::loadFromFile("src/api/static.index.html");
        return ResponseFactory::createResponse(Status::CODE_200, response_str);
    }

};
