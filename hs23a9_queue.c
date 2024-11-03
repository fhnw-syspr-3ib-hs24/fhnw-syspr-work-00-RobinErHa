#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
#include <stdio.h> 


struct count {
	pthread_mutex_t m;
	volatile int n;
};

struct count ticket = { PTHREAD_MUTEX_INITIALIZER, 0 };
struct count served = { PTHREAD_MUTEX_INITIALIZER, 0 };

void *queue(void *arg){
	pthread_mutex_lock(&ticket.m);
	ticket.n++;
	pthread_mutex_unlock(&ticket.m);
	return NULL;
}

//void *serve(void *arg){
//	pthread_mutex_lock(&ticket.m);
//	if (ticket.n > 0){
//		ticket.n--;
//	pthread_mutex_lock(&served.m);
//	served.n++;
//	pthread_mutex_unlock(&served.m);
//	pthread_mutex_unlock(&ticket.m);
//	} else{
//	pthread_mutex_unlock(&ticket.m);
//	}
//	return NULL;
//}

void *serve(void *arg){
    pthread_mutex_lock(&ticket.m);
    if (ticket.n > 0){
        ticket.n--;
        pthread_mutex_unlock(&ticket.m);
        
        pthread_mutex_lock(&served.m);
        served.n++;
        printf("Tickets served: %d\n", served.n);
        pthread_mutex_unlock(&served.m);
    } else{
        pthread_mutex_unlock(&ticket.m);
    }
    return NULL;
}


int main() {
	for (int i = 0; i < 3; i++) {
		pthread_t server;
		pthread_create(&server, NULL, serve, NULL);
		pthread_detach(server);
	}

	while (1) { // forever
	pthread_t client;
	pthread_create(&client, NULL, queue, NULL);
	pthread_detach(client);
	printf("Tickets: %d\n", ticket.n);
	printf("Tickets served: %d\n", served.n);
	}
}
