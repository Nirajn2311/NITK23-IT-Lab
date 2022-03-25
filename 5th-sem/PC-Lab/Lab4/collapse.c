#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, j, k;
#pragma omp parallel
  {
#pragma omp for schedule(static, 3) private(i, j, k) collapse(3)
    for (i = 0; i < 4; i++)
      for (j = 0; j < 2; j++)
        for (k = 0; k < 2; k++)
        {
          int tid2 = omp_get_thread_num();
          printf("tid=%d, i=%d j=%d k=%d\n", omp_get_thread_num(), i, j, k);
        }
  }

  return 0;
}