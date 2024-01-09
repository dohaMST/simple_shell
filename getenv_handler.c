#include "shell.h"

/**
 * getenv_handler - Function to retrieve the value of an environment variable.
 * @x: Name of the environment variable to look for.
 *
 * Return: The value of the environment variable if found, otherwise, NULL.
 */
char *getenv_handler(char *x)
{
	char *tmp, *key, *val, *envr;
	int i;

	/* Loop through the environment variables */
	for (i = 0; environ[i]; i++)
	{
		/* Duplicate the current environment variable for parsing */
		tmp = strdup_handler(environ[i]);
		/* Extract the key (variable name) from the environment variable */
		key = strtok(tmp, "=");
		/* Check if the key matches the desired variable name */
		if (strcmp(key, x) == 0)
		{
			/* If found, extract the value and duplicate it */
			val = strtok(NULL, "\n");
			envr = strdup_handler(val);
			/* Free the duplicated environment variable and return the value */
			free(tmp);
			return (envr);
		}
		free(tmp), tmp = NULL;
	}
	/* Return NULL if the environment variable with the given name is not found */
	return (NULL);
}
