#include <stdio.h>
#include <unistd.h>
#include "bsm_encode.h"
#include "bsm_decode.h"

int main()
{
    uint8_t buffer[128];
    BSMcoreData bsm;
    BSMcoreData decoded;

    // Initialize static fields
    bsm.id[0] = 0x01;
    bsm.id[1] = 0x02;
    bsm.id[2] = 0x03;
    bsm.id[3] = 0x04;
    bsm.secMark = 12345;
    bsm.lat = 400000000;
    bsm.lon = -800000000;
    bsm.elev = 100;
    bsm.speed = 50;
    bsm.heading = 90;

    for (int i = 0; i < 128; i++)
    {
        bsm.msgCnt = i % 128; // msgCnt cycles 0..127

        int bits = bsm_encode(&bsm, buffer, sizeof(buffer));
        if (bits < 0)
        {
            fprintf(stderr, "Encoding failed\n");
            return 1;
        }
        printf("Encoded %d bits\n", bits);
        printf("Encoded %d bytes\n", (bits + 7) / 8);
        printf("Encoded BSM (msgCnt=%d): \n", bsm.msgCnt);
        for (size_t j = 0; j < (size_t)(bits + 7) / 8; j++)
            printf("%02X ", buffer[j]);
        printf("\n");

        // Decode
        int decoded_bits = bsm_decode(&decoded, buffer, sizeof(buffer));
        if (decoded_bits < 0)
        {
            fprintf(stderr, "Decoding failed\n");
            return 1;
        }
        printf("Decoded BSM (msgCnt=%d):\n", bsm.msgCnt);
        bsm_print(&bsm);

        
        usleep(1000000);
    }

    return 0;
}