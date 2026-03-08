# j2735-bsm-codec

A minimal C implementation of a bit-level encoder and decoder for the Basic Safety Message (BSM) CoreData defined in SAE J2735.

This project focuses on understanding how V2X messages can be serialized at the bit level before applying full ASN.1 UPER encoding.

Initial implementation of BSM encoder/decoder
- Implement bitstream reader/writer for bit-level serialization
- Add BSMcoreData structure
- Implement bsm_encode() and bsm_decode()
- Add round-trip example test

## Features
- Bit-level read/write utilities (bitstream)
- Encoder for BSMcoreData
- Decoder for BSMcoreData
- Encode → decode round-trip verification example

## Build
Compile the example encode/decoder test:
`` cd examples && make ``
Run the example:
``./encode_decode`` or ``./encode_test``
Sample output:


Example output:
```
Encoded 163 bits
Encoded 21 bytes
Decoded BSM:
  msgCnt   : 127
  id       : 01 02 03 04
  secMark  : 12345
  lat      : 400000000
  lon      : -800000000
  elev     : 100
  speed    : 50
  heading  : 90
```

## Notes
- This implementation currently performs manual bit packing for a subset of BSM coreData fields (Study still on going)
- Full compliance with ASN.1 Unaligned Packed Encoding Rules (UPER) is not yet implemented

## Roadmap
- Implement PER helpers
- Implement full BSMcoreData layout from SAE J2735
- Automated testing
- Decode real-world BSM captures

## References
- The SAE J2735 V2X Message Set, V2X ASN.1 Module Collection 2024