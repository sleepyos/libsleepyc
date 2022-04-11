#include <sleepyc/string.h>
#include <stdlib.h>
#include "unity.h"

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
	StringBuf_t buf = StringBufNew(256);
	StringFormatBuffer(buf, "> {:s} {:d} {:#X} <", "nya", 128, 0xCAFEBABE);
	TEST_ASSERT_EQUAL_STRING(buf.ref.ptr, "> nya 128 0xCAFEBABE <");

	StringBufFree(buf);
}

int main
(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_string_format_everything);
	return UNITY_END();
}
