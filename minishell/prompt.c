#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *my_getline(char *lineptr, size_t *n);

int main(void)
{
	char *comando;

	size_t length = 0;

	printf("$ ");

	comando = (char *)malloc(100);
	if (comando == NULL)
	{
		return 1;
	}

	my_getline(comando, &length);
	comando[length] = '\0';

	char *token = strtok(comando, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	free(comando);

	return (0);
}

char *my_getline(char *lineptr, size_t *n)
{
	int c;
	size_t i = 0;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		lineptr[i++] = c;
	}

	if (c == EOF)
	{
		*n = 0;
	}
	else
	{
		*n = i;
	}

	return (lineptr);
}
