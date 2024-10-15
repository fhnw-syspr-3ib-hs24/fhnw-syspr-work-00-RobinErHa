#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fd_original = open("./my.txt", O_RDONLY|O_APPEND);
	int fd_copy = open("./my_txt_copy.txt", O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR);
	
	char buf[32];
	ssize_t r = read(fd_original, buf, 32);
	while(r > 0) {
		ssize_t w = write(fd_copy, buf, r);	
		if (w == -1) {
			printf("Error while writing to file\n Error: %d\n", errno);
			return 1;
		}
		r = read(fd_original, buf, 32);
	}
        if (r == -1) {
		printf("Error while reading file\n Error: %d\n", errno);
		return 1;
	}
	close(fd_original);
	close(fd_copy);	
	return 0;
}
