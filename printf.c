#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 *_printf - produces output based on format
 *@format: string that specifies the format of the input
 *
 *Return: int
 */

int _printf(const char *format, ...)
{
	int i;
	va_list ap;

	va_start(ap, format);
	i = 1;
	
	if (format)
	{
		while (format[i])
		{
			if (format[i - 1] == '%')
			{
				switch(format[i])
				{
					case 'd':
						itoa(va_arg(ap, int))
