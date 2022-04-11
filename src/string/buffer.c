#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <sleepyc/string.h>
#include <sleepyc/memory.h>

StringBuf_t StringBufNew
(size_t cap)
{
	char *ptr = MemoryAllocate(cap);
	MemorySetByte(ptr, cap, 0);

	StringBuf_t buf;
	buf.mut.ptr = ptr;
	buf.mut.len = cap;
	buf.cap = cap;

	return buf;
}

void StringBufFree
(StringBuf_t buf)
{
	MemoryFree(buf.mut.ptr);
}
