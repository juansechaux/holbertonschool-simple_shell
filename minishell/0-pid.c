#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid, my_pidparent;

	my_pidparent = getppid();
	my_pid = getpid();
	printf("%u\n%u\n", my_pidparent, my_pid);

	return (0);
}
