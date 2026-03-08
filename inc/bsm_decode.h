#ifndef BSM_DECODE_H
#define BSM_DECODE_H

#include "bsm_types.h"
#include "bitstream.h"
#include <stddef.h>
#include <stdint.h>

int bsm_decode(BSMcoreData *bsm, uint8_t *buffer, size_t buffer_size);
void bsm_print(const BSMcoreData *bsm);

#endif