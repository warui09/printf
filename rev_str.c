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
	char temp;

	i = 0;
	j = _strlen(str) - 1;

	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
