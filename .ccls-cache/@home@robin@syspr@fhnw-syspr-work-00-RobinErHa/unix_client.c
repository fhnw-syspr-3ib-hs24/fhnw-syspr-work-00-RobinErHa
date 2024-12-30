#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/un.h>
#include <string.h>


int main(void)
{

	struct sockaddr_un addr_un;
	addr_un.sun_family = AF_UNIX;
	strcpy(addr_un.sun_path, "/tmp/mysock");

	struct sockaddr *addr = (struct sockaddr *) &addr_un;
	socklen_t addrlen = sizeof(struct sockaddr_un);

	int fd = socket(AF_UNIX, SOCK_STREAM, 0 );
	connect(fd, addr, addrlen);
	write(fd, "hello", 5);
	int len = 32;
	char buf[len];
	int r = read(fd, buf, len);
	write(STDOUT_FILENO, buf, r);
	close(fd);
}
