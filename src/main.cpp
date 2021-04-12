#include <iostream>
#include "HTTPSClient.h"
#include "TLS/Random.h"

int main() {
    HTTPSClient client;
    std::string response;

    HTTPRequest request("https://store.steampowered.com");
    client.get(request, response);

    std::cout << response << "\n";
    return 0;
}
