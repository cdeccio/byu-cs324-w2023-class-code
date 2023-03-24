#include<stdio.h>
#include<unistd.h>
#include<omp.h>


int main() {
	omp_set_num_threads(2);
#pragma omp parallel
	printf("hello world\n");
	printf("hello world again\n");
}
