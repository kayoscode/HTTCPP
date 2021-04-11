#ifndef INCLUDE_TCPCLIENT_H
#define INCLUDE_TCPCLIENT_H

#include <string>
#include <stdint.h>

/**
 * Interface for handling a TCP connection
 * @author Bryce Young (April 11, 2021)
 * */
class TCPClient {
    public:
        /**
         * Constructor
         * @param address the host domain name or ip
         * @param port the port to connect to (http 80)
         * */
        TCPClient(const std::string& address, int port);
        ~TCPClient();

        /**
         * Sends data to the server
         * @param toSend include the data to send to the server
         * */
        void send(const std::string& toSend);

        /**
         * Receive data from the server
         * @param data a buffer to store the data
         * @param size the max amount of data to store in sed buffer
         * @return total bytes sent from the server
         * */
        int receive(char* data, int size);

    private:
        bool connect();

        uint32_t sock;
        uint32_t port;
        std::string address;
};

#endif