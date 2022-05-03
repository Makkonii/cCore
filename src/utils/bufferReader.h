#ifndef CCORE_BUFFERREADER_H
#define CCORE_BUFFERREADER_H

#include <stdint-gcc.h>
#include <stdlib.h>
#include <string.h>
#include <byteswap.h>

void bytesToArray(void *dest, const uint8_t *buffer, size_t offset, size_t byteCount);

void bytesToUint32(uint32_t *dest, const uint8_t *buffer, size_t offset);

void bytesToUint16(uint16_t *dest, const uint8_t *buffer, size_t offset);

void changeEndianArray(uint8_t *arr, uint8_t arrLngth);
void changeEndianUint16(uint16_t *uint16);
void changeEndianUint32(uint32_t *uint32);

#endif //CCORE_BUFFERREADER_H
