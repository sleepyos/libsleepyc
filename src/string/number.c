#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sleepyc/string.h>

static int CharToDigit
(char ch)
{
	if ('0' <= ch && ch <= '9')
	{
		return ch - '0';
	} else if ('a' <= ch && ch <= 'f')
	{
		return (ch - 'a') + 10;
	} else
	{
		return -1;
	}
}

/**
 * Convert a string to a number, in the given radix.
 */
signed long long int StringToNumberRadix
(const char *str, size_t *chars_read, size_t radix)
{
	char *orig_str = (char *)str;
	signed long long int ret = 0;
	bool neg = false;

	if (radix < 2 || radix > 16)
	{
		// TODO: error = E_INVALID;
		return -1;
	}

	if (*str == '-')
	{
		neg = true;
		str++;
	}

	for (; CharToDigit(*str) < radix; str++)
	{
		int digit = CharToDigit(*str);
		if (digit == -1)
		{
			break;
		}

		ret = radix * ret + digit;
	}

	*chars_read = (size_t)(orig_str - str);
	return neg ? -ret : ret;
}
