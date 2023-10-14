#include "main.h"
#include <stdarg.h>
int _printf(const char *format, ...)
{
	va_list list;
	int task = 0;


	if (format == NULL)
	{
		return -1;
	}
	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			task++;
		}
		else
		{
			format++;
			if  (*format == '\0')
			{
				break;
			}
			else if (*format == 'c')
			{

				char c = va_arg(list, int);
				write(1, &c, 1);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				task++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char*);

				/*calculating the length of string*/
				int length = 0;
				while (str[length] != '\0')
					length++;
				write(1, str, length);
				task += length;
			}
		}
		va_end(list);
		format++;
	}
	return (task);
}
