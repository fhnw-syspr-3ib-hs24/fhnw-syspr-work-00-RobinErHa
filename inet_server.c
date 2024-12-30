#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>




int main(void)
{
	struct sockaddr_in addr_in;
	addr_in.sin_port = htons(8080);
	addr_in.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &addr_in.sin_addr);

	struct sockaddr *addr = (struct sockaddr *) &addr_in;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	int server_fd = socket(AF_INET, SOCK_STREAM, 0 );
	int res = bind(server_fd, addr, addrlen);
	if (res == -1) { perror("bind"); return -1;}
	listen(server_fd, 5); //typischer Wert fuer die Backlog-queue: 5
	while (1) {
		int client_fd = accept(server_fd, NULL, NULL); //blocking
		int len = 4096;
		char buf[len];
		int r = read(client_fd, buf, len);
		write(STDOUT_FILENO, buf, r);
		write(client_fd, buf, r); //echo
		close(client_fd);
	}
}
