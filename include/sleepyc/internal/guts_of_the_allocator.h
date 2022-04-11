#include <stdint.h>
#include <stddef.h>

#ifndef __SLEEPYC__GUTS_OF_THE_ALLOCATOR_H
#define __SLEEPYC__GUTS_OF_THE_ALLOCATOR_H

// Memory region handling

typedef struct SCAllocatedRegion_s {
	void *ptr;
	size_t len;
	struct SCAllocatedRegion_s *next;
} SCAllocatedRegion_t;

/* memory/alloc/region.c */

extern SCAllocatedRegion_t *SCAllocatedRegion_head;
extern SCAllocatedRegion_t *SCAllocatedRegion_tail;
extern SCAllocatedRegion_t *SCAllocatedRegion_getForPtr(void *);
extern SCAllocatedRegion_t *SCAllocatedRegion_newFromPtrSize(void *, size_t);
extern void SCAllocatedRegion_destroy(SCAllocatedRegion_t *);

// Raw allocation functions

extern void *MemoryAllocate__raw(size_t);
extern void MemoryFree__raw(void *, size_t);

#endif /* __SLEEPYC__GUTS_OF_THE_ALLOCATOR_H */
