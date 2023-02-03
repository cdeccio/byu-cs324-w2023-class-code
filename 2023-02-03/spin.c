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
	int pid;
	int status;

	if ((pid = fork()) == 0) {
		sleep(5);
		exit(2);
	}
	//kill(pid, SIGINT);
	wait(&status);
	if (WIFEXITED(status)) {
		printf("exit status: %d\n", WEXITSTATUS(status));
	} else {
		printf("exited with signal: %d\n", WTERMSIG(status));
	}

}
