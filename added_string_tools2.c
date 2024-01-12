#include "shell.h"

/**
 * revstr_handler - a function that reverses a string.
 * @str: The string to be reversed.
 * @len: The length of the string.
 */
void revstr_handler(char *str, int len)
{
	char tr;
	int beg = 0;
	int end = len - 1;

	/* Continue swapping characters until the beg idx is less than the end idx */
	while (beg < end)
	{
		/* Swap characters at the start and end positions */
		tr = str[beg];
		str[beg] = str[end];
		str[end] = tr;

		/* Move the start index forward and the end index backward */
		beg++;
		end--;
	}
}

/**
 * handle_itoa - a function that converts an integer to a string.
 * @x: The integer we wanna convert.
 * Return: the converted string
 */
char *handle_itoa(int x)
{
	char buff[20]; /* Buffer to store characters of the resulting string */
	int a = 0; /* Index for the buffer */

	/* Handle the case when n is 0 */
	if (x == 0)
		buff[a++] = '0';
	else
	{
		while (x > 0)
		{
			buff[a++] = (x % 10) + '0'; /* Convert digit to character and store */
			x /= 10; /* Move to the next digit */
		}
	}

	buff[a] = '\0'; /* Null-terminate the string */
	revstr_handler(buff, a); /* Reverse the string to get the correct order */

	/* Return a dynamically allocated string (using strdup) with the result */
	return (strdup(buff));
}


/**
 * _puts -  function to print the shell prompt
 * @str: String to print.
 */

void _puts(char *str)
{
	unsigned int len;

	len = strlen(str);
	write(STDOUT_FILENO, str, len);
}
