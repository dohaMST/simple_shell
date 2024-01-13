#include "shell.h"

/**
 * str_cmp - a function to compare 2 strings
 * @str1: string1
 * @str2: string2
 * @len: the size of string1
 * Return: 1 or -1
 */
int str_cmp(char *str1, char *str2, unsigned int len)
{
	unsigned int var_len;
	unsigned int i;

	var_len = str_len(str2);
	if (var_len != len)
		return (-1);
	i = 0;
	/* Comparing */
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (1); /* not equal. */
		i++;
	}
	return (0); /* equal*/
}

/**
 * str_ncmp - Compares two strings (name and variable) up to
 * @str1: Name supplied by the user to search for.
 * @str2: Variable to compare against.
 * @len: Length to compare up to.
 * Return: 1 or -1
 */
int str_ncmp(char *str1, char *str2, unsigned int len)
{
	unsigned int i;

	i = 0;

	while (i < len)
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * str_cpy - a function to copy a string
 * @dest: destination.
 * @src: source.
 * Return: destination string
 */
char *str_cpy(char *dest, char *src)
{
	int a;
	int b = str_len(src);

	for (a = 0; a <= b; a++)
		dest[a] = src[a];
	return (dest);
}

/**
 * str_len - a function to calculate size
 * @str: String to be calculated
 * Return: size of string
 */
int str_len(char *str)
{
	int a = 0;

	while (str[a] != '\0')
		a++;
	return (a);
}
