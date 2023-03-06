#include<stdio.h>
#include<pthread.h>

void *mythreadfunc(void *arg) {
	printf("hello world from thread\n");
}

int main() {
	pthread_t tid;
	pthread_create(&tid, NULL, mythreadfunc, NULL);
}
