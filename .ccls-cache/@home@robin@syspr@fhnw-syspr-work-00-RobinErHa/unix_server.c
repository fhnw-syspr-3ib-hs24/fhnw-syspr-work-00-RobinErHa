#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/un.h>
#include <string.h>



int main(void)
{
	unlink("/tmp/mysock");
	struct sockaddr_un addr_un;
	addr_un.sun_family = AF_UNIX;
	strcpy(addr_un.sun_path, "/tmp/mysock");

	struct sockaddr *addr = (struct sockaddr *) &addr_un;
	socklen_t addrlen = sizeof(struct sockaddr_un);

	int server_fd = socket(AF_UNIX, SOCK_STREAM, 0 );
	int res = bind(server_fd, addr, addrlen);
	if (res == -1) { perror("bind"); return -1;}
	listen(server_fd, 5); //typischer Wert fuer die Backlog-queue: 5
	while (1) {
		int client_fd = accept(server_fd, NULL, NULL); //blocking
		int len = 32;
		char buf[len];
		int r = read(client_fd, buf, len);
		write(STDOUT_FILENO, buf, r);
		write(client_fd, buf, r); //echo
		close(client_fd);
	}
}
