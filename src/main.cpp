#include <iostream>
#include "HTTPClient.h"

int main() {
    HTTPClient client;
    std::string response;

    HTTPRequest request("www.brycemyoung.com");
    client.get(request, response);

    std::cout << response << "\n";
    return 0;
}
