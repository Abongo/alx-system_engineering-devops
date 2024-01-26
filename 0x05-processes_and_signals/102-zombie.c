#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int infinite_while(void)
{
	while (1)
	{
	sleep(1);
	}
	return (0);
}

int main(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
	pid_t child_pid = fork();

	if (child_pid > 0)
	{
	// Parent process
	printf("Zombie process created, PID: %d\n", child_pid);
	}
	else if (child_pid == 0)
	{
	// Child process exits immediately, becoming a zombie
	exit(0);
	}
	else
	{
	// Fork failed
	perror("fork");
	return (1);
	}
	}

	infinite_while(); // Keep the parent process alive

	return (0);
}
