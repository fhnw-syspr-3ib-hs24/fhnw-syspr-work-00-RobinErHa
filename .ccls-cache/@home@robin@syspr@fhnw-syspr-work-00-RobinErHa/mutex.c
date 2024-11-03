#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int g = 0;
int n;

void *start(void *arg) {
	printf("start() %ld\n", pthread_self());
	for (int i = 0; i < n; i++){
		pthread_mutex_lock(&m);
		//>> CRITICAL SECTION
		g++; //g = g + 1;
			 //<<
		pthread_mutex_unlock(&m);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	n = atoi(argv[1]);
	printf("main() %ld \n", pthread_self() );
	pthread_t t1, t2;
	pthread_create(&t1, NULL, start, NULL);
	pthread_create(&t2, NULL, start, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Result: %d\n", g);
	return 0;
}
