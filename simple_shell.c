#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * findpath - find the path directory of the function
 * 
 * Return: 0 if it find, 1 if not.
 */
int findpath(char *argument0, char *newpath)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		snprintf(newpath, 50, "%s/%s", token, argument0);
		if (access(newpath, X_OK) == 0)
		{
			return (0);
		}
		token = strtok(NULL, ":");
	}
	return (1);
}


/**
 * main - main function.
 *
 * Return: Always 0.
 */

int main()
{
	char *line = NULL;
	size_t line_len = 0;
	char *args[10];
	int status;
	ssize_t line_read;
	pid_t child_pid;
	int i;

	while (1)
	{
		if (isatty(fileno(stdin)))
		{
			printf("#cisfun$ ");
		}

		line_read = getline(&line, &line_len, stdin);
		if (line_read == -1)
		{
			free(line);
			exit(0);
		}

		/* Elimina el salto de linea final */
		if (line_read > 0 && line[line_read - 1] == '\n')
		{
			line[line_read - 1] = '\0';
		}
		/* val si es solo una linea de espacios */
		for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] != ' ')
				break;
		}
		if (line[i] == '\0') /*solo se cumple si es una cadena de espacios*/
			continue;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (child_pid == 0)
		{ /* Codigo del proceso hijo */
			/* Analiza la linea de comandos en argumentos */
			int i = 0;
			args[i] = strtok(line, " ");
			while (args[i] != NULL)
			{
				i++;
				args[i] = strtok(NULL, " ");
			}
			args[i] = NULL; /* Termina la lista de argumentos */
			/*Valida si debe buscar la ruta en el PAHT*/
			if (args[0] && !strchr(args[0], '/'))
			{
				char newpath[50];
				if (findpath(args[0], newpath) == 0)
					args[0] = newpath;
				else
				{
					fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
					exit(127);
				}
			}
			/* Ejecuta el comando */
			execve(args[0], args, environ);
			perror("./shell");
			exit(127);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}

