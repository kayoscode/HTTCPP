#include <iostream>
#include "HTTPClient.h"
#include <string>

int main() {
    HTTPClient http;
    HTTPRequest request("http://www.google.com");
    std::string response;
    http.get(request, response);

    std::cout << response << "\n";
    return 0;
}
