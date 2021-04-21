#if defined(__WIN32) || defined(WIN32) || defined(_WIN32)

#include <iostream>
#include <winsock2.h>

#include "TCPClient.h"

TCPClient::TCPClient(const std::string& address, int port)
    :address(address), port(port), sock(0)
{
    if(!connect()) {
        std::cout << "Error creating connection\n";
    }
}

bool TCPClient::connect() {
    WSADATA wsaData;
    SOCKADDR_IN addr;

    //startup wsa
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    this->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(this->sock == INVALID_SOCKET) {
        WSACleanup();
        return false;
    }

    //setup ipv4 connection
    addr.sin_family = AF_INET;
    addr.sin_port = htons(this->port);

    //get host ip
    struct hostent* ip = gethostbyname(address.c_str());

    if(ip == nullptr) {
        return false;
    }

    //copy data from IP to struct
    //bcopy(ip->h_addr, &addr.sin_addr, ip->h_length);
    memcpy(&addr.sin_addr, ip->h_addr_list[0], ip->h_length);

    if(::connect(sock, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        //printf("Client: connect() failed! Error code: %ld\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
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
    closesocket(sock);
    WSACleanup();
}

#endif
