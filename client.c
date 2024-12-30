#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>



int main(void)
{
	struct sockaddr *addr;
	socklen_t addrlen;

	int fd = socket(AF_UNIX, SOCK_STREAM, 0 );
	connect(fd, addr, addrlen);
	write(fd, "hello", 5);
	int len = 32;
	char buf[len];
	int r = read(fd, buf, len);
	write(STDOUT_FILENO, buf, r);
	close(fd);
}
