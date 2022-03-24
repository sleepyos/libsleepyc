#include <stddef.h>
#include <stdint.h>
#include <sleepyc/memory.h>

/**
 * Set a memory region at `ptr` with length `len` to the byte `byte`
 */
void MemorySetByte
(void *ptr, size_t len, uint8_t byte)
{
	uint8_t *p = (uint8_t *)ptr;
	for (size_t i = 0; i < len; i++)
	{
		p[i] = byte;
	}
}
