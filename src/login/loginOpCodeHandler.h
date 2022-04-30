#ifndef CCORE_LOGINOPCODEHANDLER_H
#define CCORE_LOGINOPCODEHANDLER_H

#include "loginStructs.h"
#include "../utils/bufferReader.h"

struct challengeClient parseLogonChallenge(const uint8_t *buffer);

#endif //CCORE_LOGINOPCODEHANDLER_H
