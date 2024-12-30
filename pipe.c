#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int fds[2];
	pipe(fds);
	int res = fork();
	if (res == 0) {
		close(fds[0]);
		int len = strlen(argv[1]);
		write(fds[1], argv[1], len);
		exit(0);
	}
	close(fds[1]);
	int len = 1024;
	char buf[len];
	int r = read(fds[0], buf, len);
	write(STDOUT_FILENO, buf, r);
	printf("\n");
	return 0;
}
