#include "HTTPSClient.h"
#include "TCPClient.h"

#include "TLS/TLSHandshake.h"
#include "TCPClient.h"

#define TLS_VERSION "1.0"

HTTPSClient::HTTPSClient() {

}

HTTPSClient::~HTTPSClient() {

}

void HTTPSClient::get(HTTPRequest& request, std::string& response) {
    TCPClient connection(request.url.getHost(), HTTPS_PORT);
}

void HTTPSClient::post(HTTPRequest& request, std::string& response) {

}
