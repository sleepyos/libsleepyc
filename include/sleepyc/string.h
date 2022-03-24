#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#ifndef __SLEEPYC__STRING_H
#define __SLEEPYC__STRING_H

/* string/format.c */

extern size_t StringFormatBuffer_va(char *, size_t , const char *, va_list);
extern size_t StringFormatBuffer(char *, size_t , const char *, ...);

/* string/misc.c */

extern size_t StringLength(const char *);
extern char *StringReverse(char *);
extern size_t StringCopyBounded(const char *, size_t, char *);
extern size_t StringCopy(const char *, char *);

/* string/number.c */
extern signed long long int StringToNumberRadix(const char *, size_t *, size_t);

#endif /* __SLEEPYC__STRING_H */
