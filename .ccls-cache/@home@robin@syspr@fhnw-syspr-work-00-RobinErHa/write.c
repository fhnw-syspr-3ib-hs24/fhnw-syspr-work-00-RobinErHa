#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Usage: %s <filename> <String>", argv[0]);
		return -1;
	}

	char *buf = argv[2];
	size_t n = strlen(buf);
	//Create if not yet, write only - User Read (chmod) und User write(chmod)
	int fd = open(argv[1], O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR );

	//seek the current Position to write to  -> END at the end of the file
	//lseek(fd, 0, SEEK_END); - achtung race conditions (MUTEX etc.)
	//O_APPEND writes to the end of the file
	//-> Veraendert die Operation von Write
	ssize_t w =	write(fd, buf, n);
	if (w == -1) {
		perror("write");
		return -1;
	}

	close(fd);
	return 0;
}
