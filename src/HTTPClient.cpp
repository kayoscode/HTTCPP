#include <iostream>
#include <sstream>

#include "HTTPClient.h"

HTTPClient::HTTPClient() 
{
}

HTTPClient::~HTTPClient() {
}

void HTTPClient::get(const HTTPRequest& request, std::string& resp) {
    std::stringstream req;
    std::string version = "1.1";

    //create GET request text
    req << "GET / HTTP/" << version << "\r\nHOST: " << request.host << "\r\n" << "Connection: close\r\n\r\n";
    TCPClient connection(request.host, 80);
    connection.send(req.str());

    int bytesRead = 0;

    //read all bytes from server response and store in string stream
    do {
        char response[5000] = { 0 };
        bytesRead = connection.receive(response, 5000);

        resp += response;
    } while(bytesRead > 0);
}

void HTTPClient::post(const HTTPRequest& request, std::string& response) {
    //TODO
}