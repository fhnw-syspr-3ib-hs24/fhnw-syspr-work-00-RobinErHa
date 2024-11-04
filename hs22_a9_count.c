#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


long count = 0;
int done = 0;

void handler(int sig){
	done = 1;
}



int main(void)
{
	signal(SIGALRM, handler);
	alarm(1);
	while (!done){
		count++;
	}
	printf("%ld", count);
	return EXIT_SUCCESS;
}
