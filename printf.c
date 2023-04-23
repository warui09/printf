#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *_printf - produce output according to format
 *@format: string to print
 *Return: number of characters printed excluding the null
 *        bytes used to end strings
 */

int _printf(const char *format, ...)
{
/*	va_list ap;*/
/*	char *a;*/
	int i, j;

	i = 0;
	j = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			write(1, &format[i + 1], 1);
			j++;
		}
		else
		{
			write(1, &format[i], 1);
			j++;
		}
		i++;
	}
	return (j);
}
