#ifndef INCLUDE_TLS_HANDSHAKE_H
#define INCLUDE_TLS_HANDSHAKE_H

#include "HTTPSClient.h"
#include "TCPClient.h"

#define TLS_RANDOM_SIZE 32

class TLSHandshake {
    public:
        /**
         * Initiates the session
         * */
        TLSHandshake();

        /**
         * Initiates an HTTPS connection using a TLS handshake
         * */
        void performTLSHandshake(TCPClient& tcpConnection);

    private:
        char clientRandom[TLS_RANDOM_SIZE];
        char serverRandom[TLS_RANDOM_SIZE];
};

#endif