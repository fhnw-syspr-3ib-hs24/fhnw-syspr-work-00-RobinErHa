#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *name;

int f(int n) {
// Convert integer 'n' to a string
		char *c = malloc(sizeof(char));
        sprintf(c, "%d", n);
		char *argv_exec[] = {name, c, NULL}; 

	pid_t f = fork();
    if (f == 0) { // child
		execve(name, argv_exec, NULL);
	}
	int status;
	wait(&status);
	return WEXITSTATUS(status);
}

int main(int argc, char *argv[]) {
	name = argv[0];
	int n = atoi(argv[1]);
	if (n < 3) {
		return 1;
	} else {
		return f(n - 1) + f(n - 2);
	}
}
