#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include <sys/wait.h>

void myspecialfunc(int signum) {
	printf("just kidding %d\n", signum);
}

int main(int argc, char *argv[]) {
	int i;

	sigset_t new_set, old_set;

	// setup signal handler
	struct sigaction sigact;
	sigact.sa_handler = myspecialfunc;
	sigact.sa_flags = 0;

	sigaction(SIGINT, &sigact, NULL);

	sigemptyset(&new_set);
	sigaddset(&new_set, SIGINT);
	sigprocmask(SIG_BLOCK, &new_set, &old_set);

	for (i = 0; i < 1000; i++) {
		if (i == 10) {
			sigprocmask(SIG_SETMASK, &old_set, NULL);
		}
		printf("main loop %d\n", i);
		sleep(1);
	}
}
