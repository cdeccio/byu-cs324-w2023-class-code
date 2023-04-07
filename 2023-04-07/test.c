#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int i = 0;
	if (fork() == 0) {
		i++;
	} else {
		i--;
	}
	printf("x: %x %d\n", &i, i);
}
