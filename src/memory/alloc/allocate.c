#include <sleepyc/memory.h>
#include <sleepyc/internal/guts_of_the_allocator.h>

void *MemoryAllocate
(size_t len)
{
	void *ret = MemoryAllocate__raw(len);
	if (ret == NULL)
	{
		return NULL;
	}

	SCAllocatedRegion_newFromPtrSize(ret, len);
	MemorySetByte(ret, len, 0);
	return ret;
}
