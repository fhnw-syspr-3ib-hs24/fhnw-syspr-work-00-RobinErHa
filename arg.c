#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *start(void *arg) {
	int j = *((int *) arg);
	printf("start(), j = %d \n", j);
	return NULL;
}

int main()
{
	printf("main() %ld \n", pthread_self() );
	pthread_t t;
	int i = 7;
	void *arg = &i;
	pthread_create(&t, NULL, start, arg);
	pthread_join(t, NULL);
	return 0;
}
