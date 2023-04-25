#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *printf - print formated output
 *@format: string to print
 *Return: number of characters printed
 */

int printf(const char *format, ...)
{
	va_list ap;
	int i, j;
	char c[20];

	i = 0, j = 0;
	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			j++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'd':
				case 'i':
					itoa(va_arg(ap, int), c, 10);
					write(1, c, _strlen(c) + 1);
					break;
				default:
					write(1, &format[i - 1], 1);
					write(1, &format[i], 1);
					j += 2;
					break;
			}
		}
		i++;
	}
	va_end(ap);
	return (j);
}
