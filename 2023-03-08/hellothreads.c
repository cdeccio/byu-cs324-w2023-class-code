#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>


void *mythreadfunc(void *arg) {
	printf("hello world from thread %d\n", getpid());
}

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, mythreadfunc, NULL);
	sleep(2);
}
