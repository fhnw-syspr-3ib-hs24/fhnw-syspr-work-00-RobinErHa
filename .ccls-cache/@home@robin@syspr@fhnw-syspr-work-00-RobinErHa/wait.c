#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	printf("main()\n");
	pid_t res = fork();
	if (res == 0) { // child
		printf("child\n");
		sleep(1);
		exit(-1); // child fork finish
	}
	int status;
	  wait(&status); //blocking - wartet auf child prozess
		printf("parent, child done, status = %d.\n", (signed char) WEXITSTATUS(status));
		return 0;
}
