#include <iostream>
#include "HTTPClient.h"
#include "HTTPSClient.h"

int main() {
    HTTPClient client;
    std::string response;
    std::string response2;

    HTTPRequest request("www.brycemyoung.com");
    client.get(request, response);

    std::cout << response << "\n";

    HTTPRequest request2("www.steam.com");
    client.get(request2, response2);

    std::cout << response2 << "\n";
    return 0;
}