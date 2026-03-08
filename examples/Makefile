SRC_DIR = ../src
INC_DIR = ../inc
SRC_NAMES = bitstream bsm_encode bsm_decode
SRC_FILES = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_NAMES)))
CFLAGS = -Wall -Wextra -I$(INC_DIR)

EXAMPLES = encode_decode encode_test

all: $(EXAMPLES)

encode_decode: encode_decode.c $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $@

encode_test: encode_test.c $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXAMPLES)

.PHONY: all clean