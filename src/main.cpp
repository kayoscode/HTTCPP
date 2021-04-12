#include <iostream>
#include "AESEngine.h"

int main() {
    unsigned char keyData[16] { 0x0f, 0x00, 0x71, 0xc9, 0x47, 0xd9, 0xe8, 0x59, 0x1c, 0xb7, 0xad, 0xd6, 0xaf, 0x7f, 0x67, 0x98 };
    AESKey* key = new AESKey(keyData, AESKeyType::AES_KEY128);
    AESEngine aes(key);

    std::string output;
    aes.encyrptText("0321456789abcdeffedcba9876543210", output);

    return 0;
}
