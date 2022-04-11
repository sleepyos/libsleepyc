#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <sleepyc/string.h>
#include <sleepyc/number.h>

size_t StringFormatBuffer__putc
(char ch, StringBuf_t buf, size_t *bufi)
{
	if (*bufi >= buf.cap)
	{
		return 0;
	}

	buf.mut.ptr[(*bufi)++] = ch;
	buf.mut.ptr[*bufi] = '\0';

	return 1;
}

size_t StringFormatBuffer__puts
(char *ch, size_t ch_len, StringBuf_t buf, size_t *bufi)
{
	if ((*bufi + ch_len) >= buf.cap)
	{
		ch_len = buf.cap - *bufi - 1;
	}

	for (size_t i = 0; i < ch_len; i++)
	{
		buf.mut.ptr[(*bufi)++] = ch[i];
	}

	buf.mut.ptr[*bufi] = '\0';
	return ch_len;
}

size_t StringFormatBuffer_va
(StringBuf_t buf, const char *fmt, va_list ap)
{
	size_t fmt_len = StringLength(fmt);

	size_t bufi = 0;
	size_t fmti = 0;
	char pbuf[38];

	char *ptr;
	size_t len;

	while (fmti <= fmt_len)
	{
		if (bufi >= buf.cap)
			break;

		char ch = fmt[fmti];
		if (ch != '{')
		{
			StringFormatBuffer__putc(ch, buf, &bufi);
			fmti++;
			continue;
		}

		ch = fmt[++fmti];
		if (ch == ':')
		{
			// XXX: it's C, we can't use named parameters
			ch = fmt[++fmti];
		}

		// Check for requested zero-padding
		size_t zero_pad = 0;
		if (ch == '0')
		{
			size_t chars_read = 0;
			zero_pad = (size_t)StringToNumberRadix(&fmt[fmti], &chars_read, 10);
			fmti += chars_read;
		}

		// Check for alternate-mode specifier
		bool alt_mode = false;
		if (ch == '#')
		{
			alt_mode = true;
			fmti++;
		}

		// Switch on type
		switch (fmt[fmti])
		{
			case 0:
				return bufi;

			case 'c':
				StringFormatBuffer__putc((char)va_arg(ap, int), buf, &bufi);
				break;

			case 's':
				ptr = va_arg(ap, char*);
				StringFormatBuffer__puts(ptr, StringLength(ptr), buf, &bufi);
				break;

			case 'u':
			case 'd':
				len = NumberToStringRadix(va_arg(ap, long long int), 10, (ch == 'u'), zero_pad, pbuf);
				StringFormatBuffer__puts(pbuf, len, buf, &bufi);
				break;

			case 'x':
			case 'X':
				if (alt_mode)
				{
					StringFormatBuffer__puts("0x", 2, buf, &bufi);
				}

				len = NumberToStringRadix(va_arg(ap, long long int), 16, true, zero_pad, pbuf);
				StringFormatBuffer__puts(pbuf, len, buf, &bufi);
				break;

			case '}':
				fmti++;
				break;

			default:
				break;
		}

		if (fmt_len > fmti && fmt[fmti + 1] == '}')
		{
			fmti++;
		}

		fmti++;
	}

	return bufi;
}

size_t StringFormatBuffer
(StringBuf_t buf, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);

	size_t ret = StringFormatBuffer_va(buf, fmt, ap);

	va_end(ap);
	return ret;
}
