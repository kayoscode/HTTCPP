#ifndef INCLUDE_TLS_HANDSHAKE_H
#define INCLUDE_TLS_HANDSHAKE_H

/**
 * Implementation of the TLS handshake based on specifications 
 * from:
 * https://tools.ietf.org/html/rfc5246
 * 
 * @author Bryce Young April 11, 2021
 * */

/**
 * The version of TLS 1.x
 * */
enum class TLSVersion {
    TWO
};

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