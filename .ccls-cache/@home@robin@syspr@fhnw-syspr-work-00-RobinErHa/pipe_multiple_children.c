
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{	
	int fd[2];
	pipe(fd);
	int res[3];	

	for (int i = 0; i < 3; i++){
		res[i] = fork();	
		if (res[i] == 0) {
			close(fd[0]); //close read end of pipe
			char* str = "hello\n";
			write(fd[1], str, strlen(str));
			close(fd[1]); //close write end of pipe
			exit(0);
		}
	}

	//synchronize here with wait(NULL) in a fori to wait for all child processes to terminate
	//to prevent zombies
	close(fd[1]); //close write end from parent process

	ssize_t n;
	char buf[1024];

	//clean way to read from the pipe, reading until read signals EOF -> read returns 0
	while((n= read(fd[0], buf, sizeof(buf))) > 0){ //read blocks until EOF signal -> When all processes close write end of pipe
		write(STDOUT_FILENO, buf, n);
	}
	printf("\n");
	return 0;
}
