#include "loginOpCodeHandler.h"

struct challengeClient parseLogonChallenge(const uint8_t *buffer) {
    struct challengeClient c;
    bytesToArray(c.version, buffer, 0x08,
                 sizeof(c.version));

    bytesToUint16(&c.build, buffer, 0x0B);
    changeEndianUint16(&c.build);

    bytesToArray(c.platform, buffer, 0x0D,
                 sizeof(c.platform));
    changeEndianArray(c.platform, sizeof(c.platform));

    bytesToArray(c.os, buffer, 0x11, sizeof(c.os));
    changeEndianArray(c.os, sizeof(c.os));

    bytesToArray(c.locale, buffer, 0x15, sizeof(c.locale));
    changeEndianArray(c.locale, sizeof(c.locale));

    bytesToUint32(&c.worldregion_bias, buffer, 0x19);
    changeEndianUint32(&c.worldregion_bias);

    bytesToUint32(&c.ip, buffer, 0x1D);

    c.account_name_length = buffer[0x21];
    bytesToArray(c.account_name, buffer, 0x22,
                 c.account_name_length);
    return c;
}