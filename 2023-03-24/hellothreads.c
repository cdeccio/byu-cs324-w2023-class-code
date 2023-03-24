#include<stdio.h>
#include<unistd.h>
#include<omp.h>


int main() {
#pragma omp parallel sections
	{
		printf("hello world\n");
#pragma omp section
		printf("hello world again\n");
#pragma omp section
		printf("hello world too\n");
	}
}
