#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int count = 0;
#pragma omp threadprivate(count)
int main(void)
{
  int x = 10, y = 20, a[10], b[10], c[10], i;
  //int count=0;
  for (i = 0; i < 10; i++)
    b[i] = c[i] = i;
  printf("1. count=%d\n", count);
#pragma omp parallel num_threads(2) copyin(count)
  {
#pragma omp for schedule(static, 5) firstprivate(x)
    for (i = 0; i < 10; i++)
    {
      int tid1 = omp_get_thread_num();
      a[i] = b[i] + c[i];
      count++;
      x++;
      printf("tid=%d,a[%d]=%d, count=%d x=%d\n", tid1, i, a[i], count, x);
    }
#pragma omp barrier
    printf("2. before copyprivate count=%d x=%d tid=%d\n", count, x, omp_get_thread_num());
#pragma omp parallel copyin(count)
    {
      count = count + 20;
    }
    printf("3. after copyprivate count=%d x=%d tid=%d\n", count, x, omp_get_thread_num());
#pragma omp for schedule(static, 5) firstprivate(x)
    for (i = 0; i < 10; i++)
    {
      int tid1 = omp_get_thread_num();
      a[i] = b[i] * c[i];
      count++;
      x++;
      printf("tid=%d,a[%d]=%d, count=%d, x=%d\n", tid1, i, a[i], count, x);
    }
  }
#pragma omp barrier
  printf("4. count=%d x=%d\n", count, x);
  printf("\n");
  return 0;
}