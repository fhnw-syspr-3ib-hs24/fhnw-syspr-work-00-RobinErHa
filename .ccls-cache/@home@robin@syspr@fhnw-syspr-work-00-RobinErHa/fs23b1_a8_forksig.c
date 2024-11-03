#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>


void handle(int signal){
	printf("I got SIGUSR1 from parent %d\n", getppid());
}

int main(void)
{
	pid_t child = fork();
	if (child == 0) { //child process
		signal(SIGUSR1, handle);
		pause();
	} else { //parent process
		sleep(2);
		kill(child, SIGUSR1);
		wait(NULL);
		printf("Child %d got SIGUSR1 from me\n", child);
	}
	return 0;
}
