#include<stdio.h>
#include<unistd.h>
#include<omp.h>


int main() {
#pragma omp parallel sections
	{
		printf("hello world %d\n",
				omp_get_thread_num());
#pragma omp section
		printf("hello world again %d\n",
				omp_get_thread_num());
#pragma omp section
		printf("hello world too %d\n",
				omp_get_thread_num());
	}
}
