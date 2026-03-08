#include "bitstream.h"
#include <stdio.h>

void bitstream_init(BitStream *bs, uint8_t *buffer, size_t size)
{
    bs->buffer = buffer;
    bs->size = size;
    bs->bitpos = 0;

    for (size_t i = 0; i < size; i++)
        bs->buffer[i] = 0;
}

int bitstream_write_bits(BitStream *bs, uint32_t value, uint8_t bits)
{
    if (bits > 32)
        return -1;

    if ((bs->bitpos + bits) > (bs->size * 8))
        return -1;

    for (int i = bits - 1; i >= 0; i--)
    {
        uint8_t bit = (value >> i) & 1;
        size_t byte_pos = bs->bitpos / 8; // byte idx
        size_t bit_offset = 7 - (bs->bitpos % 8); // reverse
        bs->buffer[byte_pos] |= (bit << bit_offset); //masking
        bs->bitpos++;

    }
    return 0;
}

uint32_t bitstream_read_bits(BitStream *bs, uint8_t bits)
{
    uint32_t value = 0;

    if (bits > 32)
        return 0;

    for (uint8_t i = 0; i < bits; i++)
    {
        size_t byte_pos = bs->bitpos / 8;
        size_t bit_offset = 7 - (bs->bitpos % 8);
        if (byte_pos >= bs->size)
            return 0;
        uint8_t bit = (bs->buffer[byte_pos] >> bit_offset) & 1;
        value = (value << 1) | bit;
        bs->bitpos++;
    }
    return value;
}