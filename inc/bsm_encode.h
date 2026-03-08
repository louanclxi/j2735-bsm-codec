#ifndef BSM_ENCODE_H
#define BSM_ENCODE_H

#include "bsm_types.h"
#include "bitstream.h"

int bsm_encode(const BSMcoreData *bsm, uint8_t *buffer, size_t buffer_size);

#endif
