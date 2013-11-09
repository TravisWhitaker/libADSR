# libADSR Copyright (C) Travis Whitaker Stephen Demos 2013

# libADSR is developed with clang:
CC=clang
CFLAGS= -Wall -Wextra -Werror -pedantic -O2 -pipe -march=native
DEBUG_CFLAGS= -Wall -Wextra -Werror -pedantic -O0 -g -pipe -DDEBUG_MSG_ENABLE
INCLUDE= -I./include

# You make need to change this to '-fpic' if you're using a strange
# architecture like ancient SPARC or MIPS:
FPIC= -fPIC

# Archiver for building the static library:
AR=ar
ARFLAGS=rvs

# Defualt values for user-supplied compile time directives:
DEBUG_MSG=

# Enable debugging messages outside of the 'debug' target:
ifeq ($(DEBUG_MSG),y)
	CFLAGS += -DDEBUG_MSG_ENABLE
endif

.PHONY: all
all: libadsr.a test

libadsr.a:
	$(AR) $(ARFLAGS) libadsr.a

.PHONY: test
test: libadsr.a
	make -C test

.PHONY: test.debug
test.debug: libadsrdebug.a
	make -C test debug

.PHONY: debug
debug: libadsrdebug.a test.debug

libadsrdebug.a:
	$(AR) $(ARFLAGS) libadsrdebug.a

.PHONY: check
check: test

.PHONY: clean
clean:
	rm -f libadsr.a
	rm -f libadsr.so
	rm -f libadsrdebug.a
	rm -f *.o*
	make -C test clean
