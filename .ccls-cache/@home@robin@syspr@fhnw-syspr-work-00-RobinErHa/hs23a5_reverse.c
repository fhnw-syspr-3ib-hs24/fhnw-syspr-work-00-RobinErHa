#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR);
	
	int file_length = lseek(fd, 0, SEEK_END);
	
	for (int i =0; i < file_length/2; i++){
		char buff_start[1];
		char buff_end[1];
		
		lseek(fd, i, SEEK_SET);
		read(fd, buff_start, 1);
		
		lseek(fd, - (i + 1), SEEK_END);
		read(fd, buff_end, 1);
		
		lseek(fd, - (i +1), SEEK_END);
		write(fd, buff_start, 1);

		lseek(fd, i, SEEK_SET);
		write(fd, buff_end, 1);
	}
	close(fd);
	
	return 0;
}
