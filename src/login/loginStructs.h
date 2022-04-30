#ifndef CCORE_LOGINSTRUCTS_H
#define CCORE_LOGINSTRUCTS_H

#include <stdint-gcc.h>

struct challengeClient {
    uint8_t version[3];
    uint16_t build;
    uint8_t platform[4];
    uint8_t os[4];
    uint8_t locale[4];
    uint32_t worldregion_bias;
    uint32_t ip;
    uint8_t account_name_length;
    uint8_t account_name[255];
};

struct challengeServer{
    uint8_t opcode;
    uint8_t protocol_version;
    uint8_t result;
    uint8_t server_public_key[32];
    uint8_t generator_len;
    uint8_t generator;
    uint8_t large_safe_prime_len[32];
    uint8_t salt[32];
    uint8_t crc_salt[16];

};

#endif //CCORE_LOGINSTRUCTS_H
