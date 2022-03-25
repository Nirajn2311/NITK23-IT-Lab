// #include <omp.h>
// #include <stdio.h>

// void main()
// {
//   int x = 0;
// #pragma omp parallel num_threads(6) reduction(+ \
//                                               : x)
//   {
//     int id = omp_get_thread_num();
//     int threads = omp_get_num_threads();
//     x = x + 1;
//     printf("Hi from %d\n value of x : %d\n", id, x);
//   }
//   printf("Final x:%d\n", x);
// }

#include <omp.h>
#include <stdio.h>

int main(void)
{
  int tid, p, a[50], sum = 0, dsum=0, finalsum;
  int i, low, high;
  int n = 20;

  for (i = 0; i < 20; i++)
  {
    a[i] = i;
    dsum = dsum + i;
  }

  printf("\n1. dsum=%d\n", dsum);
#pragma omp parallel num_threads(4) default(shared) private(tid, low, high, i) reduction(+ \
                                                                                         : sum)
  {
    p = omp_get_num_threads();
    int tid = omp_get_thread_num();

    low = tid * n / p;
    high = (tid + 1) * n / p;
    printf("\n2.Thread [%d] low=%d high=%d\n", tid, low, high);

    for (i = low; i < high; i++)
    {
      dsum = dsum + a[i];
    }
  }

  printf("\n4. finalsum=%d\n", dsum);
  return 0;
}