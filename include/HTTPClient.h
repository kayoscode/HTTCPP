#ifndef INCULDE_HTTPCLIENT_H
#define INCLUDE_HTTPCLIENT_H

#include <string>
#include <map>

#include "TCPClient.h"

/**
 * HTTP version supported.
 * 1.VERSION NUMBER
 * ZERO = 1.0
 * ONE = 1.1,
 * TWO = 1.2
 * */
enum class HTTPVersion {
    ONE, //version 1.1
};

/**
 * Structure containing an http request
 * @author Bryce Young
 * */
struct HTTPRequest {
    /**
     * @param host the host name or ip
     * @param version the version of http to use (Defaults to http1.1)
     * */
    HTTPRequest(const std::string& host, HTTPVersion version = HTTPVersion::ONE) 
        :host(host), version(version)
    {}

    /**
     * Sets a variable for the request
     * @param name the name of the new variable
     * @param value the value for that variable as a str
     * */
    void setVariable(const std::string& name, const std::string& value) {
        variables[name] = value;
    }
    
    /**
     * Removes a variable from the list of vars by name
     * @param name the name of the variable to remove
     * */
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

/**
 * Controller for sending basic HTTP requests
 * @author Bryce Young
 * */
class HTTPClient {
    public:
        HTTPClient();
        ~HTTPClient();

        /**
         * Creates a get request
         * @param request information about the request
         * @param response the full response from the server
         * */
        void get(const HTTPRequest& request, std::string& response);

        /**
         * Creates a post request
         * @param request information about the request
         * @param response the full response from the server
         * */
        void post(const HTTPRequest& request, std::string& response);
};

#endif