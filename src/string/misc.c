#include <stddef.h>
#include <stdint.h>
#include <sleepyc/string.h>

/**
 * Returns the length of the string `str`.
 */
size_t StringLength
(const char *str)
{
	size_t i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	return i;
}

/**
 * Reverses a string in-place.
 */
char *StringReverse
(char *str)
{
	size_t len = StringLength(str);
	for (size_t i = 0; i < len / 2; i++)
	{
		char j = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = j;
	}

	return str;
}

/**
 * Copies a string from `src` to `dest` - copying at most `len` bytes,
 * and null-terminating the destination string.
 */
size_t StringCopyBounded
(const char *src, size_t len, char *dest)
{
	size_t i = 0;
	for (; i < len && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';
	return i;
}

/**
 * Copies a string from `src` to `dest`.
 */
size_t StringCopy
(const char *src, char *dest)
{
	return StringCopyBounded(src, StringLength(src), dest);
}
