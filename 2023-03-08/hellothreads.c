#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


void *mythreadfunc(void *arg) {
	printf("hello world from thread %d\n", getpid());
	close(1);
}

int main() {
	pthread_t tid[2];
	int i;
	for (i = 0; i < 2; i++) {
		pthread_create(&tid[i], NULL, mythreadfunc, NULL);
		sleep(1);
	}
	sleep(10);
}
