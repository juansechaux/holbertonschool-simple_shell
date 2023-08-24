#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * findpath - find the path directory of the function
 * @argument0: argument to serch
 * @newpath: buffer to the route of the path
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
 * checkcommand - function to check the command that the user give.
 * @line: buffer that have the command
 * Return: void.
 */

void checkcommand(char *line)
{
	pid_t child_pid;
	int i, status;
	char *args[10];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (child_pid == 0)
	{ /* Codigo del proceso hijo */
		/* Analiza la linea de comandos en argumentos */
		i = 0;
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
		}
		/* Ejecuta el comando */
		execve(args[0], args, environ);
		perror("./shell");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}


/**
 * main - main function.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *line = NULL, **env = environ;
	size_t line_len = 0;
	ssize_t line_read;
	int i;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("#cisfun$ ");
		line_read = getline(&line, &line_len, stdin);
		if (line_read == -1)
		{
			free(line);
			exit(0);
		}
		line[strcspn(line, "\n")] = '\0';/* Elimina el salto de linea final */
		for (i = 0; line[i] != '\0'; i++)/* val si es solo una linea de espacios */
		{
			if (line[i] != ' ')
				break;
		}
		if (line[i] == '\0') /*solo se cumple si es una cadena de espacios*/
			continue;
		if (strcmp(line, "exit") == 0)
			break; /*quite el "free(line); y exit(0)"*/
		else if (strcmp(line, "env") == 0) /*imprimir el env*/
		{
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else /*llama a la funcion para ejecutar el comando*/
			checkcommand(line);
	}
	free(line);
	return (0);
}
