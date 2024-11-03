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
	pthread_t t1, t2;
	pthread_create(&t1, NULL, start, NULL);
	pthread_create(&t2, NULL, start, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
