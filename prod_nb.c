#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

#define STOCK_MAX 10
int stock = 0;

void *produce(void *arg) {
	printf("start() %ld\n", pthread_self());
	while(1){
		int res = pthread_mutex_trylock(&m); //non-blocking
											 
		if (res == 0) {
		if (stock < STOCK_MAX){
		//>> CRITICAL SECTION
		stock++; //g = g + 1;
		printf("%d\n", stock);
			 //<<
		pthread_mutex_unlock(&m);
		} 
		}else {
			printf(":(\n");
		}
	}
	return NULL;
}
void *consume(void *arg) {
	printf("start() %ld\n", pthread_self());
	while(1){
		if (stock > 0){
		pthread_mutex_lock(&m);
		//>> CRITICAL SECTION
		stock--; //g = g + 1;
		printf("%d\n", stock);
			 //<<
		pthread_mutex_unlock(&m);
		}
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	printf("main() %ld \n", pthread_self() );
	pthread_t t1, t2;
	pthread_create(&t1, NULL, produce, NULL);
	pthread_create(&t2, NULL, consume, NULL);
	 pthread_join(t1, NULL); // blocking
    pthread_join(t2, NULL); // blocking
	return 0;
}
