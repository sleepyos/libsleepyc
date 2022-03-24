#include <stddef.h>
#include <stdint.h>

#ifndef __SLEEPYC__MEMORY_H
#define __SLEEPYC__MEMORY_H

/* memory/misc.c */

extern void MemorySetByte(void *, size_t, uint8_t);

/* memory/alloc/allocate.c */

extern void *MemoryAllocate(size_t);

/* memory/alloc/free.c */

extern void MemoryFree(void *);

#endif /* __SLEEPYC__MEMORY_H */
