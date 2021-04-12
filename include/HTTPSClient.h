#ifndef INCLUDE_HTTPSCLIENT_H
#define INCLUDE_HTTPSCLIENT_H

#include <string>
#include "HTTPClient.h"

#define HTTPS_PORT 443

/**
 * Creates an HTTPS request interface
 * */
class HTTPSClient {
    public:
        HTTPSClient();
        ~HTTPSClient();

        /**
         * Create an HTTPS get request
         * @param request details about the request
         * @param response the response from the server
         * */
        void get(HTTPRequest& request, std::string& response);

        /**
         * Create an post request
         * @param request details about the request
         * @param response the response from the server
         * */
        void post(HTTPRequest& request, std::string& response);

    private:
};

#endif