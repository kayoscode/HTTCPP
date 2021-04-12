#include <iostream>
#include <sstream>
#include <string>
#include <map>

#include "HTTPClient.h"
#include "URL.h"

std::map<char, std::string> charToURLEncoding {
    { ' ', "+" }
};

HTTPRequest::HTTPRequest(const std::string& url, HTTPVersion version)
    :version(version), url(url)
{
}

static bool isAlphaNum(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');

}

static void encodeNonAlphaURL(char ch, std::string& output) {
    if(charToURLEncoding.find(ch) != charToURLEncoding.end()) {
        output += charToURLEncoding[ch];
    }
}

static void encodeStringForURL(const std::string& str, std::string& encoded) {
    for(int i = 0; i < str.size(); ++i) {
        if(isAlphaNum(str[i])) {
            encoded += str[i];
        }
        else {
            encodeNonAlphaURL(str[i], encoded);
        }
    }
}

//https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/POST
static std::string getVariablesURLEncoded(const HTTPRequest& request) {
    std::string ret;

    for(std::map<std::string, std::string>::const_iterator i = request.variables.begin(); i != request.variables.end(); ++i) {
        std::string var, value;

        encodeStringForURL(i->first, var);
        encodeStringForURL(i->second, value);

        ret += var + "=" + value;

        if(std::next(i) != request.variables.end()) {
            ret += '&';
        }
    }

    return ret;
}

static std::string getVariablesMultipartFormData(const HTTPRequest& request) {
    return "";
}

HTTPClient::HTTPClient(){
}

HTTPClient::~HTTPClient() {
}

void HTTPClient::get(const HTTPRequest& request, std::string& resp) {
    std::stringstream req;
    std::string version = "1.1";
    std::string variablesURL = getVariablesURLEncoded(request);
    std::cout << variablesURL << "\n";

    //create GET request text
    req << "GET " << request.url.getPath() << " HTTP/" << version << "\r\nHOST: " << request.url.getHost() << "\r\n" << "Connection: close\r\n\r\n";
    TCPClient connection(request.url.getHost(), HTTP_PORT);
    connection.send(req.str());

    int bytesRead = 0;

    //read all bytes from server response and store in string stream
    do {
        char response[5001] = { 0 };
        bytesRead = connection.receive(response, 5000);

        resp += response;
    } while(bytesRead > 0);
}

void HTTPClient::post(const HTTPRequest& request, std::string& response) {
    //TODO
}
