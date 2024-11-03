#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *start(void *arg) {
	printf("start() %ld\n", pthread_self());
	return NULL;
}

int main()
{
	printf ("main()\n");
	pthread_t t[3];
	for (int i = 0; i < 3; i++) {
		pthread_create(&t[i], NULL, start, NULL);
		pthread_detach(t[i]);
	}
	pthread_exit(NULL);
}
