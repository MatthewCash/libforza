CC=gcc

DEBUG_CFLAGS=-Wextra -g -O0
RELEASE_CFLAGR=-Wextra -O2 -DNDEBUG

SRC_DIR=src/
OBJ_DIR=obj/
LIB_DIR=lib/

SRCS:=$(shell find $(SRC_DIR) -name '*.c')
OBJS:=$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
OBJ_DIRS:=$(dir $(OBJS))

LIB = $(LIB_DIR)libforza.a

.PHONY: all
all: debug

debug: CFLAGS=$(DEBUG_CFLAGS)
debug: $(LIB)

release: clean
release: CFLAGS=$(RELEASE_CFLAGR)
release: $(LIB)

# Create directories for objects
$(OBJ_DIRS):
	mkdir -p $@

# Create directory for library file
$(LIB_DIR):
	mkdir -p $@

# Compile C files to objects
$(OBJS): $(SRCS) $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Package library
$(LIB): $(LIB_DIR) $(OBJS)
	rm -f $(LIB)
	ar -cvrs $(LIB) $(OBJS)

.PHONY: clean
clean:
	rm -r $(OBJ_DIR)