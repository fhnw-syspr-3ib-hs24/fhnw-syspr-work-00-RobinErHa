
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	int fd[2];
	pipe(fd);
	int res = fork();
	if (res == 0){
		close(fd[0]); //close the reading end of the pipe
					  //child only uses the write end:
		int len = strlen(argv[1]);
		write(fd[1], argv[1], len);
		exit(0);
	}
	close(fd[1]); //closing write end of the pipe -> EOF Signals when all writing descriptors to the pipe are closed
				  //Parent uses only the read end:
	int len = 1024;
	char buf[len];
	int r = read(fd[0], buf, len);
	write(STDOUT_FILENO, buf, r);
	printf("\n");
	return 0;
}
