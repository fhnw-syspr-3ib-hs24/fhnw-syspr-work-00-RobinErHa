#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: %s <file>\n", argv[0]);
		return -1;
	}
	int fd = open(argv[1], O_RDONLY );
	if (fd == -1) {
		perror("open"); //reads errno
		return 1; //fail fast
	}
	

	//reading:
	size_t n = 32;
	char buf[n]; // stack
	ssize_t s = 1;
	while (s > 0) {
		s = read(fd, buf, n);
		write(STDOUT_FILENO, buf, s);
	}
	return 0;
}
