#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int i = 0;
	printf("x: %x\n", &i);
	printf("m: %x\n", main);
}
