#if defined(__unix__) || defined(__unix)

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>

#include "TCPClient.h"

TCPClient::TCPClient(const std::string& address, int port) 
    :address(address), port(port), sock(0)
{
    if(!connect()) {
        std::cout << "Error creating connection\n";
    }
}

bool TCPClient::connect() {
    //create socket
    this->sock = socket(AF_INET, SOCK_STREAM, 0);

    //error of the socket didn't get created successfully
    if(this->sock < 0) {
        return false;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(this->port);

    //get host ip
    struct hostent* addr = gethostbyname(address.c_str());

    if(addr == nullptr) {
        std::cout << "ASDFDASF\n";
        return false;
    }

    //copy data from IP to struct
    bcopy(addr->h_addr, &server.sin_addr, addr->h_length);

    //connect via TCP
    if(::connect(this->sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cout << "Failed to connect\n";
        return false;
    }

    return true;
}

void TCPClient::send(const std::string& toSend) {
    ::send(sock, toSend.c_str(), toSend.size(), 0);
}

int TCPClient::receive(char* data, int size) {
    return ::recv(sock, data, size, 0);
}

TCPClient::~TCPClient() {
    close(sock);
}

#endif