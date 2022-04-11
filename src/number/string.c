#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sleepyc/string.h>
#include <sleepyc/number.h>

/**
 * Convert a number to a string, in the given radix.
 */
size_t NumberToStringRadix
(long long int num, size_t radix, bool unsig, size_t zero_pad, char *buf)
{
	long long int tmp = num;
	size_t bufi = 0;

	if (radix > 36)
	{
		return 0;
	}

	if (num < 0 && !unsig)
	{
		num = -num;
		buf[bufi++] = '-';
	}

	// Build the string in reverse
	do
	{
		size_t value = ((size_t) tmp % radix);
		buf[bufi++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[value];
		tmp /= radix;
	} while (tmp > 0);

	buf[bufi] = '\0';
	StringReverse(buf);
	return bufi;
}
