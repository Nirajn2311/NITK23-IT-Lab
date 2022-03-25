#include <stdio.h>
#include <omp.h>

int main()
{
  int i = 20;
  printf("Value of i before pragma i=%d\n", i);
#pragma omp parallel num_threads(4) private(i)
  {
    printf("Value after entering pragma i=%d tid=%d\n", i, omp_get_thread_num());
    i = i + omp_get_thread_num(); //adds thread_id to i
    printf("Value after changing value i=%d tid=%d\n", i, omp_get_thread_num());
  }
  printf("Value after having pragma i=%d tid=%d\n", i, omp_get_thread_num());
}