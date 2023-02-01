#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>


void myspecialfunc(int signum) {
	printf("just kidding\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	int i;
	int pid;

	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = myspecialfunc;
	sigact.sa_flags = 0;

	sigaction(SIGCHLD, &sigact, NULL);
	
	pid = fork();
	for (i = 0; i < 1000; i++) {
		if (i == 5 && pid == 0) {
			exit(0);
		}
		printf("main loop %d\n", i);
		sleep(1);
	}
}
