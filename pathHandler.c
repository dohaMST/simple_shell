#include "shell.h"
/*

char *_getenv(char *var)
{
        char *tmp, *key, *value, *env;
        int i;

        for (i = 0; environ[i]; i++)
        {
                tmp = strdup(environ[i]);
                key = strtok(tmp, "=");

                if (strcmp(key, var) == 0)
                {
                        value = strtok(NULL, "\n");
                        env = strdup(value);
                        free(tmp);
                        return (env);
                }
                free(tmp), tmp = NULL;
        }
        return (NULL);
}

*/
char *_getpath(char *cmd)
{
	char *path_env, *full_cmd, *dir;
	struct stat st;
	int i;

	/* check if the command is already a path*/
	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0) /*the path is correct (exists)*/
				return (strdup(cmd));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");

	/* handle the case if the user unset the path and we cant get directories*/
	if (!path_env)
		return (NULL);

	/*handling path - making it*/
	dir = strtok(path_env, ":");
	
	while (dir)
	{
		full_cmd = malloc(strlen(dir) + strlen(cmd) + 2);
		if (full_cmd)
		{
			strcpy(full_cmd, dir);
			strcat(full_cmd, "/");
			strcat(full_cmd, cmd);

			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			} 
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}

