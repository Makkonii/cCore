#ifndef CCORE_LOGINOPCODEHANDLER_H
#define CCORE_LOGINOPCODEHANDLER_H

#include "loginUtils/loginStructs.h"
#include "../utils/bufferReader.h"

struct authStruct parseLogonChallenge(const uint8_t *buffer);

#endif //CCORE_LOGINOPCODEHANDLER_H
