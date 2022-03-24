#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef __SLEEPYC__NUMBER_H
#define __SLEEPYC__NUMBER_H

/* number/misc.c */

extern size_t NumberDecimalPlaces(long long int, size_t);

/* number/string.c */

extern size_t NumberToStringRadix(long long int, size_t, bool, size_t, char *);

#endif /* __SLEEPYC__NUMBER_H */
