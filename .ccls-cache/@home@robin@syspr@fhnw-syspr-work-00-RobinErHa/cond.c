#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

#define STOCK_MAX 10
int stock = 0;

void *produce(void *arg) {
	printf("start() %ld\n", pthread_self());
	while(1){
		pthread_mutex_lock(&m);
		if (stock < STOCK_MAX){
		stock++;
		pthread_cond_signal(&not_empty);
		}else {
			pthread_cond_wait(&not_full, &m);
		}
		printf("%d\n", stock);
		pthread_mutex_unlock(&m);
		}
}
void *consume(void *arg) {
	printf("start() %ld\n", pthread_self());
	while(1){
		pthread_mutex_lock(&m);
		if (stock > 0){
			stock--; //g = g + 1;
			pthread_cond_signal(&not_full);
		}else {
			pthread_cond_wait(&not_empty, &m);
		}
		printf("%d\n", stock);
		pthread_mutex_unlock(&m);
		}
	}

int main(int argc, char *argv[])
{
	printf("main() %ld \n", pthread_self() );
	pthread_t t1, t2;
	pthread_create(&t1, NULL, produce, NULL);
	pthread_create(&t2, NULL, consume, NULL);
	pthread_detach(t1);
	pthread_detach(t2);
	pthread_exit(NULL);
}
