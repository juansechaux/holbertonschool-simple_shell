#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	while (environ[i] != NULL)
	{
		char *env_var = environ[i];
		char *equal_sign = strchr(env_var, '=');

		if (equal_sign != NULL)
		{
		/*Calcula la longitud del nombre de la variable de entorno*/
			int name_length = equal_sign - env_var; /*le quita el = a PATH=*/
		/*Compara el nombre de la variable con el argumento*/
			if (strncmp(env_var, name, name_length) == 0)
			{
				return (equal_sign + 1); /*Devuelve el valor después del '='*/
			}
		}
		i++;
	}
	return (NULL);
}

int main()
{
	char *path = _getenv("LS_COLORS");
	if (path != NULL)
	{
		printf("Contenido de la variable de entorno = %s\n", path);
	}
	else
	{
		printf("Variable de entorno no encontrada.\n");
	}
	return (0);
}
