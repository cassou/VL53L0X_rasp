CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar
RM = rm

CFLAGS = -O0 -g -Wall -c

OUTPUT_DIR = bin
OBJ_DIR = obj

TARGET_LIB = $(OUTPUT_DIR)/libVL53L0X_Rasp.a

INCLUDES = \
	-I. \
	-I${API_DIR}/Api/core/inc \
	-I./platform/inc

VPATH = \
	${API_DIR}/Api/core/src \
	./platform/src/

LIB_SRCS = \
	vl53l0x_api_calibration.c \
	vl53l0x_api_core.c \
	vl53l0x_api_ranging.c \
	vl53l0x_api_strings.c \
	vl53l0x_api.c \
	vl53l0x_platform.c

LIB_OBJS  = $(LIB_SRCS:%.c=$(OBJ_DIR)/%.o)

EXAMPLES_SRC = $(wildcard examples/*)
EXAMPLES_BIN = $(EXAMPLES_SRC:examples/%.c=$(OUTPUT_DIR)/%)


.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(LIB_OBJS)
	mkdir -p $(dir $@)
	$(AR) -rcs $@ $^

$(OBJ_DIR)/%.o:%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

$(EXAMPLES_BIN): bin/%:examples/%.c
	mkdir -p $(dir $@)
	$(CC) -L$(OUTPUT_DIR) $^ -lVL53L0X_Rasp  $(INCLUDES) -o $@

examples:${OUTPUT_DIR} ${TARGET_LIB} $(EXAMPLES_BIN)

.PHONY: clean
clean:
	-${RM} -rf ./$(OUTPUT_DIR)/*  ./$(OBJ_DIR)/*


