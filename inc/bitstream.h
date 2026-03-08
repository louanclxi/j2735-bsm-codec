#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
    size_t bitpos;
} BitStream;

void bitstream_init(BitStream *bs, uint8_t *buffer, size_t size);
int bitstream_write_bits(BitStream *bs, uint32_t value, uint8_t bits);
uint32_t bitstream_read_bits(BitStream *bs, uint8_t bits);

#endif