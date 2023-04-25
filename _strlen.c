#include "main.h"

/**
 *_strlen - returns length of a string
 *@s: string to get length of
 *
 *Return: length of the string
 */

int _strlen(const char *s)
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
