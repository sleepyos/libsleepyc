.dinclude "config.mk"
.ifndef PLATFORM
.error PLATFORM is not set
.endif

CC ?= clang
CFLAGS += -nostdlib -ffreestanding -I include/ -I platform/${PLATFORM}/include/

SOURCES := ${:!find src/ -name '*.c' -print!} ${:!find platform/${PLATFORM}/src -name '*.c' -print!}
SOURCES := ${SOURCES:tw:c=o}

libsleepyc.a: ${SOURCES}
	ar rcs libsleepyc.a ${SOURCES}

clean:
	rm -f ${SOURCES} libsleepyc.a

.c.o:
	${CC} ${CFLAGS} -o ${.TARGET} -c ${.IMPSRC}

.SUFFIXES: .c .o
