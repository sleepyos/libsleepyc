#include <sys/mman.h>
#include <sleepyc/memory.h>

void *MemoryAllocate__raw
(size_t len)
{
	void *ret = mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
	{
		return NULL;
	}

	return ret;
}
