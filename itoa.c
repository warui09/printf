#include "main.h"

/**
 *itoa - convert int to string
 *@num: int to convert
 *@str: string to return
 *@base: base of number to convert
 *
 *Return: string
 */

char *itoa(int num, char *str, int base)
{
	int i, j, is_negative;
	
	i = 0;
	is_negative = 0;
	
	if (num < 0 && base == 10)
	{
		is_negative = 1;
		num = -num;
	}

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	while (num != 0)
	{
		j = num % base;
		str[i++] = (j > 9) ? (j - 10) + 'a' : j + '0';
		num = num / base;
	}

	if (is_negative)
		str[i++] = '-';

	str[i] = '\0';
	rev_str(str);
	return (str);
}
