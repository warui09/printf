#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *_strlen - returns length of a string
 *@s: string to get length of
 *
 *Return: length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
 *_printf - produce output according to format
 *@format: string to print
 *
 *Return: number of characters printed excluding the null
 *        bytes used to end strings
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char a[1];
	int i, j;
	char *b;

	i = 0;
	j = 0;
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
				case 'c':
					a[0] = (char)va_arg(ap, int);
					write(1, a, 1);
					j++;
					break;
				case 's':
					b = va_arg(ap, char *);
					write(1, b, _strlen(b));
					j += _strlen(b);
					break;
				case '%':
					write(i, &format[i], 1);
					break;
				default:
					write(1, &format[i - 1], 1);
					j++;
					break;
			}
		}
		i++;
	}
	va_end(ap);
	return (j);
}
