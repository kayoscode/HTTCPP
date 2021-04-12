#include "TLS/TLSHandshake.h"
#include "SecureRandom.h"

TLSHandshake::TLSHandshake() {
    generateRandomSequence(clientRandom, TLS_RANDOM_SIZE);
}

void TLSHandshake::performTLSHandshake(TCPClient& tcpConnection) {

}