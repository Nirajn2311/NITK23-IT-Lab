#include <stdio.h>
#include <omp.h>

int main()
{
  int x = 20;
#pragma omp parallel shared(x)
  {
    int tid = omp_get_thread_num();
    x = x + 1;
    printf("Thread [%d] value of x is %d\n", tid, x);
  }
}