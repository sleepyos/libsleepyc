#include <sys/mman.h>
#include <sleepyc/memory.h>

void MemoryFree__raw
(void *ptr, size_t len)
{
	munmap(ptr, len);
}
