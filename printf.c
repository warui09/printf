#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *_printf - produce output according to format
 *@format: string to print
 *Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char a[1], *b, c[20];
	int i, j;

	i = 0, j = 0;
	va_start(ap, format);

	if (format == NULL)
		return (-1);

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
					if (b == NULL)
					{
						write(1, "NULL", 1);
						return (-1);
					}
					write(1, b, _strlen(b));
					j += _strlen(b);
					break;
				case '%':
					write(1, &format[i], 1);
					j++;
					break;
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
