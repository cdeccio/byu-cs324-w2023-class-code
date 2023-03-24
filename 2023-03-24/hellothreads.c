#include<stdio.h>
#include<unistd.h>
#include<omp.h>


int main() {
#pragma omp parallel
	printf("hello world\n");
	printf("hello world again\n");
}
