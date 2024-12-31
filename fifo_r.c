#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	const char* new_fifo = "newFifo";
	mkfifo(new_fifo, S_IRUSR | S_IWUSR);

	int fi = open(new_fifo, O_RDONLY);
	
	char buf[32];
	size_t n = read(fi, buf, sizeof(buf));
	while (n != 0){
		for(int i = 0; i < n; i++){
			printf("%c", buf[i]);
		}
		n = read(fi, buf, sizeof(buf));
	};
	return 0;
}
