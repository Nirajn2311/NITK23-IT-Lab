#include <stdio.h>
#include <omp.h>

int main()
{
  int val;
  printf("Enter 0: for serial 1: for parallel\n");
  scanf("%d", &val);
#pragma omp parallel if (val=0)
  {
    if (omp_in_parallel())
    {
      printf("Parallel val=%d id=%d\n", val, omp_get_thread_num());
    }
    else
    {
      printf("Serial val=%d id=%d\n", val, omp_get_thread_num());
    }
  }
}
