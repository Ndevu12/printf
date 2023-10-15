#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	int task = 0;
	if (format == NULL)
		return -1;
	va start(args, format);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			_putchar(*formatr);
			task++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				_putchar(va_arg(args, int));
				task++
			}
				char *str = va_arg(args, char*);
				while (*str)
				{
					_putchar(*str++);
					task++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				task++;
			}
			else if (*format == 'd' || *format == 'i')
				task += _print_int(va_arg(args, int));
	}
		
	va_end(args);
	return task;
}
int _print_int(int n)
{
	int task = 0, sign = 1;
	unsigned int num;
	if (n < 0)
	{
		_putchar('-');
		task++;
		num = -n;
	}
	else
		num = n;
	if (num / 10)
		task += _print_int(num / 10);
	_putchar(num % 10 + '0');
	return task +1;
}
int _putchar(char c)
{
	return write(1, &c, 1);
}


