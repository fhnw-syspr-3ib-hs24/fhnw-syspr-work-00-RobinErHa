#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char* argv[])
{
	const char* new_fifo = "newFifo";
	int fi = open(new_fifo, O_WRONLY);
	
	const char* msg = argv[1];
	size_t n = strlen(msg);
	n = write(fi, msg, n);

	return 0;
}
