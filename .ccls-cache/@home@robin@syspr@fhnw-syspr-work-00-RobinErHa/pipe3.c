#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//ls | wc

int main(int argc, char *argv[])
{
	int fds[2];
	pipe(fds);
	int res = fork();
	if (res == 0) {
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		char *argvc1[] = { "ls", NULL };
		execvp("ls", argvc1);
	}
	int res2 = fork();
	if (res2 == 0) {
		close(fds[1]);
		char *argvc2[] = { "wc", NULL };
		dup2(fds[0], STDIN_FILENO);
		execvp("wc", argvc2);
	}
	close(fds[0]);
	close(fds[1]);
	return 0;
}
