#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#ifndef __SLEEPYC__STRING_H
#define __SLEEPYC__STRING_H

typedef struct StringRef {
	const char *ptr;
	size_t len;
} StringRef_t;

typedef struct StringMut {
	union {
		struct StringRef ref;
		struct {
			char *ptr;
			size_t len;
		};
	};
} StringMut_t;

typedef struct StringBuf {
	union {
		struct StringMut mut;
		struct StringRef ref;
	};
	size_t cap;
} StringBuf_t;

/* string/buffer.c */

extern StringBuf_t StringBufNew(size_t);
extern void StringBufFree(StringBuf_t);
extern StringBuf_t StringBufFromRef(StringRef_t, size_t);

/* string/format.c */

extern size_t StringFormatBuffer_va(StringBuf_t, const char *, va_list);
extern size_t StringFormatBuffer(StringBuf_t, const char *, ...);

/* string/misc.c */

extern size_t StringLength(const char *);
extern char *StringReverse(char *);
extern size_t StringCopyBounded(const char *, size_t, char *);
extern size_t StringCopy(const char *, char *);

/* string/number.c */
extern signed long long int StringToNumberRadix(const char *, size_t *, size_t);

#endif /* __SLEEPYC__STRING_H */
