#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

volatile int runs;

int main(int argc, char *argv[])
{
	pid_t pid[argc - 1];
	for (int i = 1; i < argc; i++){
		pid[i-1] = fork();
		if (pid[i-1] == 0){
			int ret = execve(argv[i], NULL, NULL);			
			if (ret == -1){
				printf("execve: No such file or directory\n");
			}
			exit(0);
		}
	}
	int i = 0;
	while (wait(&pid[i]) > 0){
		runs++;
		i++;
	}

	printf("runseq: %d of %d runs succesful\n", runs, argc -1);
	return 0;
}
