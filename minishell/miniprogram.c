#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - main function.
 *
 * Return: Always 0.
 */


int main()
{
	int i;
	pid_t son_pid;
	int status;

	for (i = 0; i < 5; i++)
	{
		son_pid = fork();

		if (son_pid == -1)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (son_pid == 0)/*Codigo del proceso hijo*/
		{
			printf("Son %d executing ls -l /tmp:\n", i + 1);
			char *args[] = {"ls", "-l", "/tmp", NULL};
			son_pid = getpid();
			printf("El pid del hijo es %u\n", son_pid);
			execve("/bin/ls", args, NULL);
			perror("Execve failed"); /* Solo se ejecuta el execve falla*/
			exit(1);
		}
		else /*Codigo del proceso padre*/
		{
			wait(&status);
			son_pid = getppid();
			printf("El pid del padre es %u\n", son_pid);
			printf("Child %d exited\n", i + 1);
		}
	}
	return (0);
}

