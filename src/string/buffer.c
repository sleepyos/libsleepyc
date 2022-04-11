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
	buf.mut.len = 0;
	buf.cap = cap;

	return buf;
}

void StringBufFree
(StringBuf_t buf)
{
	MemoryFree(buf.mut.ptr);
}

StringBuf_t StringBufFromRef
(StringRef_t ref, size_t len)
{
	if (len < ref.len) len = ref.len;

	char *ptr = MemoryAllocate(len);
	StringCopy(ref.ptr, ptr);

	StringBuf_t buf;
	buf.mut.ptr = ptr;
	buf.mut.len = StringLength(ref.ptr);
	buf.cap = len;

	return buf;
}
