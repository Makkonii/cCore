#ifndef CCORE_LOGINSTRUCTS_H
#define CCORE_LOGINSTRUCTS_H

#include <stdint-gcc.h>

struct authStruct {
    uint8_t version[3];
    uint16_t build;
    uint8_t platform[4];
    uint8_t os[4];
    uint8_t locale[4];
    uint32_t worldRegion_bias;
    uint32_t ip;
    uint8_t account_name_length;
    uint8_t account_name[255];
};
#endif //CCORE_LOGINSTRUCTS_H
