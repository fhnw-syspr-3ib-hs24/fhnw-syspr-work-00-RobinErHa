#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char *argv[])
{	
	int runs = 0;
	pid_t pid[argc - 1];
	for (int i = 1; i < argc; i++){
		pid[i-1] = fork();
		if (pid[i-1] == 0){
			int ret = execve(argv[i], NULL, NULL);			
			if (ret == -1){
				printf("execve: No such file or directory\n");
				exit(-1);
			}
			exit(0);
		} else {
			int status;
			wait(&status);
			if (status == 0) {
				runs++;
			}
		}
	}

	printf("runseq: %d of %d runs succesful\n", runs, argc -1);
	return 0;
}
