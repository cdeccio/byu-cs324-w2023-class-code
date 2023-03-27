#include<stdio.h>
#include<unistd.h>
#include<omp.h>


int main() {
#pragma omp parallel for schedule(static, 1)
	for (int i = 0; i < 12; i++) {
		printf("hello world iter=%d thread=%d\n", i,
				omp_get_thread_num());
		sleep(i);
	}
}
