#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd_read = open(argv[1], O_RDONLY);
	int fd_write = open(argv[1], O_WRONLY);
	
	char r, w;
	lseek(fd_read, 0, SEEK_SET);
	read(fd_read, &r, 1);
	read(fd_read, &w, 1); 

	int buffer_capacity = lseek(fd_read, 0, SEEK_END) - 2;

	char data;
	lseek(fd_read, 2+ r, SEEK_SET);
	read(fd_read, &data, 1);

	printf("buf[%d] = %d\n", r, data);
	
	r = (r+1) % buffer_capacity;

	lseek(fd_write, 0, SEEK_SET);
	write(fd_write, &r, 1); 
		
	close(fd_read);
	close(fd_write);
	return 0;
}
