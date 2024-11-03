#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	if (fork()) { //child process wird dann im if false -> keine infinite processess :) :
		fork();
		printf("a\n");
	exit(0);
}
printf("b\n");
}
