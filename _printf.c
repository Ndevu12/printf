#include "main.h"
#include <stdarg.h>
/**
 * _printf - it implicate printf function
 * @format: first arugment
 * Return: -1 when format is NULL OTHERWISE RETURN SIZE
 */
int _printf(const char *format, ...)
{
	va_list list;
	int task = 0;

	if (format == NULL)
	{
		return (-1);
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
			if (*format == '\0')
				break;
			task += percent_sign(format, list);
		}
		format++;
	}
	va_end(list);
	return (task);
}
