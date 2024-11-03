#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *start(void *arg) {
	int j = *((int *) arg);
	printf("start(), j = %d \n", j);

	//int k = 2 * j; -> ware uf stack
	int *p = malloc(sizeof(int));
	*p = 2*j;
	return p;
}

int main()
{
	printf("main() %ld \n", pthread_self() );
	pthread_t t;
	int i = 7;
	void *arg = &i;
	pthread_create(&t, NULL, start, arg);
	void *res;
	pthread_join(t, &res);
	int m = *((int *) res);
	printf("thread done, %d\n", m);
	return 0;
}
