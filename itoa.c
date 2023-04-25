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
	int i, j;
	
	i = 0;
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

	if (num < 0)
		str[i++] = '-';

	rev_str(str);
	str[i] = '\0';
	return (str);
}
