#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>


void *mythreadfunc(void *arg) {
	sleep(10);
	printf("hello world from thread %d\n", getpid());
}

int main() {
	pthread_t tid[2];
	int i;
	for (i = 0; i < 2; i++) {
		pthread_create(&tid[i], NULL, mythreadfunc, NULL);
	}
	sleep(1);
}
