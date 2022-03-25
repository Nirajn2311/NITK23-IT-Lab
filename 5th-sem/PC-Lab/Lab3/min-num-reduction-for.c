#include <limits.h>
#include <omp.h>
#include <stdio.h>

int main(void)
{
  int min_num = INT_MAX, i;
  int a[] = {63, 83, 99, 45, 8, 36, 57, 87, 95, 3};

  #pragma omp parallel for reduction(min: min_num)
  for (i = 0; i < 10; i++)
  {
    int tid = omp_get_thread_num();
    printf("Before min checking: THREAD %d, a[i]=%d, min=%d\n", tid, a[i], min_num);
    if (a[i] < min_num)
    {
      min_num = a[i];
    }
    printf("After min checking: THREAD %d, a[i]=%d, min=%d\n", tid, a[i], min_num);
  }

  printf("\nMinimum element of array = %d\n", min_num);
  return 0;
}