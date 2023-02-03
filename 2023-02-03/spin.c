#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void myspecialfunc(int signum) {
	printf("just kidding %d\n", signum);
}

int main(int argc, char *argv[]) {
	int i;

	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = myspecialfunc;
	sigact.sa_flags = 0;

	sigaction(SIGINT, &sigact, NULL);

	for (i = 0; i < 1000; i++) {
		printf("main loop %d\n", i);
		sleep(1);
	}
}
