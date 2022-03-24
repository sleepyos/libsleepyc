#include <sleepyc/memory.h>
#include <sleepyc/internal/guts_of_the_allocator.h>

void MemoryFree
(void *ptr)
{
	SCAllocatedRegion_t *region = SCAllocatedRegion_getForPtr(ptr);
	if (region == NULL)
	{
		return;
	}

	MemoryFree__raw(region->ptr, region->len);
	SCAllocatedRegion_destroy(region);
}
