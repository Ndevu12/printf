#include "main.h"
/**
 * percent_sign - check for next charactor sfter %
 * @str: first arugment
 * @list: list of arugments
 * Return: size of format otherwise -1
 */
int percent_sign(const char *str, va_list list)
{
	int task = 0;

	if (*str == 'c')
	{
		char c = va_arg(list, int);

		write(1, &c, 1);
		task++;
	}
	else if (*str == '%')
	{
		write(1, str, 1);
		task++;
	}
	else if (*str == 's')
	{
		char *strs = va_arg(list, char*);
		int length = 0;
		/*calculating the length of str*/
		while (strs[length] != '\0')
			length++;
		write(1, strs, length);
		task += length;
	}
	else
	{
		write(1, str, 1);
		task++;
	}
	return (task);
}
