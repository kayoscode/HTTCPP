#include <iostream>
#include "AESEngine.h"

int main() {
    unsigned char keyData[] = "0000000000000001";
    AESKey* key = new AESKey(keyData, AESKeyType::AES_KEY128);
    AESEngine aes(key);

    std::string output;
    aes.encyrptText("bryceyoungreallyisthebestpersonintheworld", output);

    return 0;
}
