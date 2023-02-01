#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>


void myspecialfunc(int signum) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("handler loop %d %d\n", i, signum);
		sleep(1);
	}
}

int main(int argc, char *argv[]) {
	int i;
	int pid;

	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = myspecialfunc;
	sigact.sa_flags = 0;

	sigaction(SIGINT, &sigact, NULL);
	sigaction(SIGTERM, &sigact, NULL);
	
	printf("%d\n", getpid());
	for (i = 0; i < 1000; i++) {
		printf("main loop %d\n", i);
		sleep(1);
	}
}
