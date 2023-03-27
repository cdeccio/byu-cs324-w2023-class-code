#include<stdio.h>
#include<unistd.h>
#include<omp.h>


int main() {
#pragma omp parallel for
	for (int i = 0; i < 12; i++) {
		printf("hello world %d %d\n", i,
				omp_get_thread_num());
	}
}
