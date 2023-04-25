#include "main.h"

/**
 *rev_str - reverse a string
 *@str: string to reverse
 *
 *Return: string
 */

void rev_str(char *str)
{
	int i, j;
	char tmp;

	i = 0;
	j = _strlen(str) - 1;

	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}
