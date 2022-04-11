#include <sleepyc/string.h>
#include <stdlib.h>
#include "unity.h"

#define TEST_BUF_LEN 256

void setUp
(void)
{
}

void tearDown
(void)
{
}

void test_string_format_everything
(void)
{
	char *buf = malloc(TEST_BUF_LEN);
	size_t len = StringFormatBuffer(buf, TEST_BUF_LEN, "> {:s} {:d} {:#X} <", "nya", 128, 0xCAFEBABE);
	TEST_ASSERT_EQUAL_MEMORY(buf, "> nya 128 0xCAFEBABE <", len);

	free(buf);
}

int main
(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_string_format_everything);
	return UNITY_END();
}
