#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	size_t fd_read = open(argv[3], O_RDONLY);	
	size_t fd_write = open(argv[1], O_WRONLY);	

	int bytes_read = atoi(argv[4]);
	lseek(fd_read, 0, SEEK_SET);
	char buf[bytes_read];
	read(fd_read, buf, bytes_read);

	lseek(fd_write, atoi(argv[2]), SEEK_SET);
	write(fd_write, buf, bytes_read);
	return 0;
}
