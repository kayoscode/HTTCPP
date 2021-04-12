#include "TLS/TLSHandshake.h"
#include "TLS/Random.h"

TLSHandshake::TLSHandshake() {
    generateRandomSequence(clientRandom, TLS_RANDOM_SIZE);
}

void TLSHandshake::performTLSHandshake(TCPClient& tcpConnection) {

}