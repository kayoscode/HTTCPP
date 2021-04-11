#ifndef INCLUDE_HTTPSCLIENT_H
#define INCLUDE_HTTPSCLIENT_H

#include <string>

struct HTTPSRequest {
};

class HTTPSClient {
    public:
        HTTPSClient();
        ~HTTPSClient();

        void get(HTTPSRequest& request, std::string& response);
        void post(HTTPSRequest& request, std::string& response);

    private:
};

#endif