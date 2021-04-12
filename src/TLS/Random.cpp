#include <random>

#include "TLS/Random.h"

typedef std::mt19937 rng;

void generateRandomSequence(char* bytes, int len) {
    std::random_device rd;
    rng random(rd());
    std::uniform_int_distribution<int> distribution(0, 255);

    for(int i = 0; i < len; i++) {
        bytes[i] = distribution(random);
    }
}