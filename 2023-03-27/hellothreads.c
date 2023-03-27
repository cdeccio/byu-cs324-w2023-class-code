#include<stdio.h>
#include<unistd.h>
#include<omp.h>


int main() {
	int k = 0;
#pragma omp parallel for
	for (int i = 0; i < 12; i++) {
		k++;
		printf("hello world iter=%d %d thread=%d\n", i, k,
				omp_get_thread_num());
	}
	printf("result: %d\n", k);
}
