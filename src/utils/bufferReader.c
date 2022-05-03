#include <stdio.h>
#include "bufferReader.h"

void
bytesToArray(void *dest, const uint8_t *buffer, size_t offset, size_t length) {
    memcpy(dest, &buffer[offset], length);
}

void bytesToUint32(uint32_t *dest, const uint8_t *buffer, size_t offset) {
    *dest = buffer[offset] | (buffer[offset + 1] << 8) |
            (buffer[offset + 2] << 16) | (buffer[offset + 3] << 24);
}

void bytesToUint16(uint16_t *dest, const uint8_t *buffer, size_t offset) {
    *dest = (buffer[offset] << 8) | buffer[offset + 1];
}

void changeEndianArray(uint8_t *arr, uint8_t arrLngth){
    for (int i = 0; i < arrLngth/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[arrLngth - 1 - i];
        arr[arrLngth - 1 - i] = temp;
    }
}

void changeEndianUint16(uint16_t *uint16){
    *uint16 = bswap_16(*uint16);
}

void changeEndianUint32(uint32_t *uint32){
    *uint32 = bswap_32(*uint32);
}