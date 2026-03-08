#include "bsm_encode.h"

int bsm_encode(const BSMcoreData *bsm, uint8_t *buffer, size_t buffer_size)
{
    if (!bsm || !buffer)
        return -1;

    BitStream bs;
    bitstream_init(&bs, buffer, buffer_size);

    uint32_t id =
        ((uint32_t)bsm->id[0] << 24) |
        ((uint32_t)bsm->id[1] << 16) |
        ((uint32_t)bsm->id[2] << 8)  |
        ((uint32_t)bsm->id[3]);

    bitstream_write_bits(&bs, bsm->msgCnt, 7);
    bitstream_write_bits(&bs, id, 32);
    bitstream_write_bits(&bs, bsm->secMark, 16);

    bitstream_write_bits(&bs, (uint32_t)bsm->lat, 32);
    bitstream_write_bits(&bs, (uint32_t)bsm->lon, 32);
    bitstream_write_bits(&bs, bsm->elev, 16);

    bitstream_write_bits(&bs, bsm->speed, 13);
    bitstream_write_bits(&bs, bsm->heading, 15);

    return bs.bitpos;
}