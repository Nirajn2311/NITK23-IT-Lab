#include <omp.h>
#include <stdio.h>
int tid, x=10;

#pragma omp threadprivate(x, tid)
int main()
{
#pragma omp parallel num_threads(4)
  {
    tid = omp_get_thread_num();
#pragma omp master
    {
      printf("Parallel Region 1 \n");
      x = x + 1;
    }
#pragma omp barrier
    if (tid == 1)
      x = x + 2;
    printf("Thread %d Value of x is %d\n", tid, x);
  } //#pragma omp barrier
#pragma omp parallel num_threads(4)
  {
#pragma omp master
    {
      printf("Parallel Region 2 \n");
    }
#pragma omp barrier
    printf("Thread %d Value of x is %d\n", tid, x);
  }
  printf("Value of x in Main Region is %d\n", x);
  return 0;
}