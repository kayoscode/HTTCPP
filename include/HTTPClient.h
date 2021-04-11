#ifndef INCULDE_HTTPCLIENT_H
#define INCLUDE_HTTPCLIENT_H

#include <string>
#include <map>

#include "TCPClient.h"

enum class HTTPVersion {
    ONE, //version 1.1
};

struct HTTPRequest {
    HTTPRequest(const std::string& host, HTTPVersion version = HTTPVersion::ONE) 
        :host(host), version(version)
    {}

    void setVariable(const std::string& name, const std::string& value) {
        variables[name] = value;
    }
    
    void removeVariable(const std::string& name) {
        std::map<std::string, std::string>::iterator var = variables.find(name);

        if(var != variables.end()) {
            variables.erase(var);
        }
    }

    HTTPVersion version;
    std::string host;
    std::map<std::string, std::string> variables;
};

class HTTPClient {
    public:
        HTTPClient();
        ~HTTPClient();

        void get(const HTTPRequest& request, std::string& response);
        void post(const HTTPRequest& request, std::string& response);
};

#endif