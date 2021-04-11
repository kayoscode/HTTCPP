#ifndef INCLUDE_TCPCLIENT_H
#define INCLUDE_TCPCLIENT_H

#include <string>
#include <stdint.h>

class TCPClient {
    public:
        TCPClient(const std::string& address, int port);
        ~TCPClient();

        /**
         * Sends data to the server
         * */
        void send(const std::string& toSend);
        int receive(char* data, int size);

    private:
        bool connect();

        uint32_t sock;
        uint32_t port;
        std::string address;
};

#endif