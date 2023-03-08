#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


void *mythreadfunc(void *arg) {
	int *x = (int *)arg;
	printf("hello world from thread %d\n", *x);
	(*x)++;
}

int main() {
	pthread_t tid[2];
	int i;
	int *x = (int *)malloc(sizeof(int));
	*x = 5;
	for (i = 0; i < 2; i++) {
		pthread_create(&tid[i], NULL, mythreadfunc, x);
		sleep(1);
	}
	sleep(10);
}
