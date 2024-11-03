#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *start(void *arg) {
	printf("start() %ld\n", pthread_self());
	return NULL;
}

int main()
{
	printf("main() %ld \n", pthread_self() );
	pthread_t t;
	pthread_create(&t, NULL, start, NULL);
	pthread_join(t, NULL);
	return 0;
}
