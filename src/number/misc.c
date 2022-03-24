#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sleepyc/number.h>

/**
 * Return the number of decimal places in the given `num`.
 */
size_t NumberDecimalPlaces
(long long int num, size_t radix)
{
	size_t decimal_places = 0;
	long long int tmp = num;

	while (tmp >= 1) {
		decimal_places++;
		tmp /= radix;
	}

	if (decimal_places == 0)
	{
		decimal_places = 1;
	}

	return decimal_places;
}
