#ifndef INCLUDE_HTTPSCLIENT_H
#define INCLUDE_HTTPSCLIENT_H

#include <string>

/**
 * Details about an HTTPS request
 * @author Bryce Young
 * */
struct HTTPSRequest {
};

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
        void get(HTTPSRequest& request, std::string& response);

        /**
         * Create an post request
         * @param request details about the request
         * @param response the response from the server
         * */
        void post(HTTPSRequest& request, std::string& response);

    private:
};

#endif