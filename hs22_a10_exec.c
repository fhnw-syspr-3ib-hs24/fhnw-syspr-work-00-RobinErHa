#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	for (int i= 0; i < atoi(argv[1]); i++){
		pid_t child = fork();
		if (child == 0){
			execve(argv[2], NULL, NULL);
			exit(0);
		}
	}
	int status = 1;
	while (status > 0){
		wait(&status);
	}
	return EXIT_SUCCESS;
}
