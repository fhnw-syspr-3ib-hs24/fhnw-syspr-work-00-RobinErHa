#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	printf("main()\n");
	pid_t res = fork();
	if (res == 0) { // child
		printf("child\n");
		exit(0); // child fork finish
	} // parent from here
		printf("parent\n");
		return 0;
}
