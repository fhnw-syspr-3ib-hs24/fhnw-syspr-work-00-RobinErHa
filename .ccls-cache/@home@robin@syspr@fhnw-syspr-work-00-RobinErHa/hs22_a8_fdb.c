#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void put(size_t fd, int index, char* word){
	lseek(fd, index*32, SEEK_SET);
	write(fd, word, strlen(word));
}

void get(size_t fd, int index){
	char c[32];
	lseek(fd, index * 32, SEEK_SET);
	read(fd, c, 32);
	printf("%s\n", c);
}

int main(int argc, char *argv[])
{	
	size_t fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

	if (argv[2][0] == 'p' && argv[2][1] == 'u' && argv[2][2] == 't' && argv[2][3] == '\0'){
			printf("was put\n");
			put(fd, atoi(argv[3]), argv[4]);
	} else {
			printf("was get\n");
			get(fd, atoi(argv[3]));
	}

	return EXIT_SUCCESS;
}
