#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;

	for (int i = 1; av[i] != NULL ; i++)
	{
		printf("El argumento %d es: %s\n", i, av[i]);
	}
	return (0);
}

