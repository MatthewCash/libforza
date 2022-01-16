CC=gcc

BASE_CFLAGS=-Wextra

DEBUG_CFLAGS=$(BASE_CFLAGS) -g -Og
RELEASE_CFLAGS=$(BASE_CFLAGS) -O2 -DNDEBUG

SRC_DIR=src/
OBJ_DIR=obj/
LIB_DIR=lib/
LIB_INSTALL_DIR=/usr/local/lib
HEADER_INSTALL_DIR=/usr/local/include

HEADER_FILE=include/forza.h

SRCS:=$(shell find $(SRC_DIR) -name '*.c')
OBJS:=$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
OBJ_DIRS:=$(sort $(dir $(OBJS)))

STATIC_LIB= $(LIB_DIR)libforza.a
DYNAMIC_LIB= $(LIB_DIR)libforza.so

.PHONY: all
all: debug

.PHONY: debug
debug: CFLAGS=$(DEBUG_CFLAGS)
debug: static

.PHONY: release
release: clean
release: CFLAGS=$(RELEASE_CFLAGS)
release: static

.PHONY: static
static: $(STATIC_LIB)

.PHONY: dynamic
dynamic: clean
dynamic: CFLAGS=$(RELEASE_CFLAGS) -fPIC
dynamic: $(DYNAMIC_LIB)

# Create directories for objects
$(OBJ_DIRS):
	mkdir -p $@

# Create directory for library file
$(LIB_DIR):
	mkdir -p $@

# Compile C files to objects
$(OBJS): $(SRCS) $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $(patsubst $(OBJ_DIR)%.o, $(SRC_DIR)%.c, $@) -o $@

# Package static library
$(STATIC_LIB): $(LIB_DIR) $(OBJS)
	rm -f $@
	ar rcs $@ $(OBJS)

# Link dynamic library
$(DYNAMIC_LIB): $(LIB_DIR) $(OBJS)
	$(CC) -fPIC -shared -o $@ $(OBJS) -lc

.PHONY: clean
clean:
	rm -f $(LIB_DIR)*
	rm -rf $(OBJ_DIR)*

.PHONY: install
install: static
	install $(STATIC_LIB) $(LIB_INSTALL_DIR)
	install $(HEADER_FILE) $(HEADER_INSTALL_DIR)