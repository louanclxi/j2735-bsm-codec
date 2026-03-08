#include "bsm_decode.h"
#include "bitstream.h"
#include <stdio.h>

int bsm_decode(BSMcoreData *bsm, uint8_t *buffer, size_t buffer_size)
{
    if (!buffer || !bsm || buffer_size < 1)
        return -1;

    BitStream bs;
    bitstream_init(&bs, buffer, buffer_size);

    bsm->msgCnt = bitstream_read_bits(&bs, 7);

    uint32_t id = bitstream_read_bits(&bs, 32);
    bsm->id[0] = (id >> 24) & 0xFF;
    bsm->id[1] = (id >> 16) & 0xFF;
    bsm->id[2] = (id >> 8) & 0xFF;
    bsm->id[3] = id & 0xFF;

    bsm->secMark = bitstream_read_bits(&bs, 16);
    bsm->lat = (int32_t)bitstream_read_bits(&bs, 32);
    bsm->lon = (int32_t)bitstream_read_bits(&bs, 32);
    bsm->elev = bitstream_read_bits(&bs, 16);

    bsm->speed = bitstream_read_bits(&bs, 13);
    bsm->heading = bitstream_read_bits(&bs, 15);

    return bs.bitpos;
}

void bsm_print(const BSMcoreData *bsm)
{
    if (!bsm)
        return;
    printf("BSMcoreData:\n");
    printf("  msgCnt   : %u\n", bsm->msgCnt);
    printf("  id       : %02X %02X %02X %02X\n", bsm->id[0], bsm->id[1], bsm->id[2], bsm->id[3]);
    printf("  secMark  : %u\n", bsm->secMark);
    printf("  lat      : %d\n", bsm->lat);
    printf("  lon      : %d\n", bsm->lon);
    printf("  elev     : %d\n", bsm->elev);
    printf("  speed    : %u\n", bsm->speed);
    printf("  heading  : %u\n", bsm->heading);
}