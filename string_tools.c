#include "shell.h"

/**
 * strlen_handler - function that returns the length of a string
 * @str: the string we wanna calucle its length
 * Return: the length of the string
*/

int strlen_handler(char *str)
{
	int count = 0;

	while (str[count] != '\0')
		count++;
	return (count);
}


/**
 * strdup_handler - a function that duplicates an string
 * @str: String we wanna duplicate
 * Return: pointer to the new string
 */
char *strdup_handler(char *str)
{
	char *newStr;
	int len, i;

	if (str == NULL)
		return (NULL);

	len = strlen_handler(str) + 1;

	newStr = malloc(sizeof(char) * len);

	if (newStr == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < len ; i++)
	{
		newStr[i] = str[i];
	}

	return (newStr);
}

/**
 * strcpy_handler - Copies a string to buffer
 * @dest: destination.
 * @src: source.
 * Return: The pointer to destinatio string.
 */

char *strcpy_handler(char *dest, char *src)
{
	int a;
	int b = strlen_handler(src);

	for (a = 0; a <= b; a++)
		dest[a] = src[a];
	return (dest);
}

/**
 * strcmp_handler - compare 2 strings.
 * @str1: first string
 * @str2: second string.
 * Return: number shows the difference.
 */
int strcmp_handler(char *str1, char *str2)
{
	int i = 0;
	int res = 0;
	int size1, size2;

	size1 = (int)strlen_handler(str1);
	size2 = (int)strlen_handler(str2);

	if (size1 != size2)
		return (-1);

	for (i = 0; ((str1[i] != '\0') && (str2[i] != '\0')); i++)
	{
		res = (str1[i] - str2[i]);
		if (res != 0)
		{
			return (res);
		}
	}
	return (0);
}

/**
 * strcat_handler - Function that concatenates two strings
 * @dest: destination string
 * @src: source String
 * Return: new pointer
*/

void strcat_handler(char *dest, char *src)
{
	int size = strlen_handler(dest);
	size_t i = 0;

	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}

	dest[size + i] = '\0';
}
