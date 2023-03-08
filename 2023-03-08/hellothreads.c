#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>


void *mythreadfunc(void *arg) {
	int *x = (int *)arg;
	printf("hello world from thread %d\n", *x);
	(*x)++;
	sleep(5);
	printf("goodbye from thread %d\n", *x);
}

int main() {
	pthread_t tid[2];
	int i;
	int *x = (int *)malloc(sizeof(int));
	*x = 5;
	for (i = 0; i < 2; i++) {
		pthread_create(&tid[i], NULL, mythreadfunc, x);
	}
	for (i = 0; i < 2; i++) {
		pthread_join(tid[i], NULL);
	}
}
