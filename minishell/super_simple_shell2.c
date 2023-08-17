#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

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

	while (1)
	{
		printf("#cisfun$ ");
		ssize_t line_read = getline(&line, &line_len, stdin);
		if (line_read == -1)
		{
			free(line);
			exit(0);
		}

		/* Elimina el salto de línea final */
		if (line_read > 0 && line[line_read - 1] == '\n')
		{
			line[line_read - 1] = '\0';
		}
		pid_t child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (child_pid == 0)
		{ /* Código del proceso hijo */
			/* Analiza la línea de comandos en argumentos */
			int i = 0;
			args[i] = strtok(line, " ");
			while (args[i] != NULL) {
				i++;
				args[i] = strtok(NULL, " ");
			}
			args[i] = NULL; /* Termina la lista de argumentos */
			/* Ejecuta el comando */
			execve(args[0], args, NULL);
			perror("Execve failed");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}

