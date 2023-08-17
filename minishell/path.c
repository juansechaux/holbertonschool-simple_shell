#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		char *path = getenv("PATH");
		char *token = strtok(path, ":");
		int found = 0;
		struct stat st;

		while (token != NULL)
		{
			char filepath[256];
			snprintf(filepath, sizeof(filepath), "%s/%s", token, argv[i]);
			if (stat(filepath, &st) == 0)
			{
				printf("%s\n", filepath);
				found = 1;
				break;
			}
			token = strtok(NULL, ":");
		}
		if (!found)
		{
			printf("%s not found\n", argv[i]);
		}
	}
	return (0);
}

