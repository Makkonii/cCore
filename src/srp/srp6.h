#ifndef CCORE_SRP6_H
#define CCORE_SRP6_H

#include <gmp.h>
#include <openssl/sha.h>
#include <string.h>

extern const uint8_t largeSafePrime[32];
extern const uint8_t generator;
extern const uint8_t key;

uint8_t *calcPasswordVerifier(char *username, char *password, uint8_t *salt);

uint8_t *calcX(char *string, char *password, uint8_t *salt);

uint8_t *calcPubKey(uint8_t *passwordVerifier, uint8_t *serverPrivateKey);

uint8_t *
calcClientSessKey(uint8_t *clientPrivateKey, uint8_t *serverPublicKey,
                  uint8_t *x, uint8_t *u);

uint8_t *
calcServerSessKey(uint8_t *clientPublicKey, uint8_t *passwordVerifier,
                  uint8_t *u, uint8_t serverPrivateKey);

uint8_t *calcU(uint8_t *clientPublicKey, uint8_t *serverPublicKey);

uint8_t *interleaved(uint8_t *serverKey);

uint8_t *calcServerProof(uint8_t *clientPublicKey, uint8_t *clientProof,
                         uint8_t *sessionKey);


#endif //CCORE_SRP6_H
