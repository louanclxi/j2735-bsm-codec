#include <stdio.h>
#include "bsm_encode.h"

int main()
{
    uint8_t buffer[128] = {0};

    BSMcoreData bsm = {
        .msgCnt = 5,
        .id = {0x01, 0x02, 0x03, 0x04},
        .secMark = 12345,
        .lat = 400000000,
        .lon = -800000000,
        .elev = 100,
        .accuracy = {1, 1, 0},
        .speed = 50,
        .heading = 90
    };

    int bits = bsm_encode(&bsm, buffer, sizeof(buffer));

    if (bits < 0)
    {
        fprintf(stderr, "Encoding failed\n");
        return 1;
    }

    printf("Encoded BSM (hex): ");
    for (size_t i = 0; i < (size_t)(bits + 7) / 8; i++)
    {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    printf("Encoded %d bits\n", bits);
    printf("Encoded %d bytes\n", (bits + 7) / 8);

    return 0;
}