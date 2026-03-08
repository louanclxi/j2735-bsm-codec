#ifndef BSM_TYPES_H
#define BSM_TYPES_H

#include <stdint.h>

/*
Derived from SAE j2735 BSMcoreData definitions
Fields simplified for first implementation
*/

typedef uint8_t MsgCount;              // INTEGER (0..127)
typedef uint8_t TemporaryID[4];        // OCTET STRING (SIZE(4))
typedef uint16_t DSecond;              // INTEGER (0..65535)

typedef int32_t Latitude;              // INTEGER (-900000000..900000001)
typedef int32_t Longitude;             // INTEGER (-1799999999..1800000001)

typedef int16_t Elevation;             // INTEGER (-4096..61439)

typedef uint16_t Speed;                // INTEGER (0..8191)
typedef uint16_t Heading;              // INTEGER (0..28800)

typedef int16_t Acceleration;          // INTEGER (-2000..2001)
typedef int8_t VerticalAcceleration;   // INTEGER (-127..127)
typedef int16_t YawRate;               // INTEGER (-32767..32767)

typedef struct {
    uint8_t semiMajor;
    uint8_t semiMinor;
    uint16_t orientation;
} PositionalAccuracy;

typedef struct {
    MsgCount msgCnt;
    TemporaryID id;
    DSecond secMark;
    Latitude lat;
    Longitude lon;
    Elevation elev;
    PositionalAccuracy accuracy;
    Speed speed;
    Heading heading;
} BSMcoreData;

#endif