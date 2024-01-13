#include "shell.h"

/**
 * get_env - a function that gets a specific environment
 * @name: the name of env we want
 * Return: environment variable
 */
char *get_env(const char *name)
{
	char **env_copy;
	char *var, *val, *path;
	int x;
	unsigned int pa_len, env_len, len, i;
	/* setting the count of els */

	env_len = 0;
	while (environ[env_len] != NULL)
		env_len++;
	/* Creating a copy of env variables*/
	env_copy = NULL;
	env_copy = copy_env(env_copy, env_len);
	/* Calculating the size  */
	len = str_len((char *)name);
	i = 0;
	while (env_copy[i] != NULL)
	{
		var = env_copy[i];
		/* Comparing the name with the env */
		x = str_ncmp((char *)name, var, len);
		if (x == 1)
		{
			/* Extracting the value*/
			val = strtok(var, "=");
			val = strtok(NULL, "\n ");
			/* Handle the errors*/
			if (val == NULL)
			{
				write(STDERR_FILENO, ERR_PATH, str_len(ERR_PATH));
				exit(EXIT_FAILURE);
			}
			/* Calculating the size */
			pa_len = str_len(val);
			/* Allocating memory for the path */
			path = malloc(sizeof(char) * pa_len + 1);
			if (path == NULL)
			{
				write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
				return (NULL);
			}
			path = str_cpy(path, val);
			free_dp(env_copy, env_len);
			return (path);
		}
		i++;
	}
	/* If theres no match */
	return (NULL);
}

/**
 * copy_env - a function to create a copy for env
 * @env_copy: the copy
 * @env_length: the length of env
 * Return: copy of env variables
 */
char **copy_env(char **env_copy, unsigned int env_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;
	/* Allocating memory */
	env_copy = malloc(sizeof(char **) * (env_length));
	if (env_copy == NULL)
	{
		/*handling errors*/
		write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
		return (NULL);
	}
	i = 0;
	while (i < env_length)
	{
		variable = environ[i];
		/* Calculating the length of env */
		variable_length = str_len(variable);
		/* Allocating memory for the copy */
		env_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (env_copy[i] == NULL)
		{
			write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
			return (NULL);
		}
		/* Copy handling*/
		str_cpy(env_copy[i], environ[i]);
		i++;
	}
	return (env_copy);
}
