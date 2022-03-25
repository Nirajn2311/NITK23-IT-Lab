#include <stdio.h>
#include <omp.h>
#include<opens

int main()
{
  int i, N, threadnum, numthreads, low, high;
  printf("Enter limit: ");
  scanf("%d", &N);
  int a[N], b[N], c[N];

  for (i = 0; i < N; i++)
  {
    a[i] = 5 * i;
    b[i] = 3 * i + 8;
  }

#pragma omp parallel default(shared) private(threadnum, numthreads, low, high, i)
  {
    int threadnum = omp_get_thread_num(), numthreads = omp_get_num_threads();
    int low = N * threadnum / numthreads, high = N * (threadnum + 1) / numthreads;

    for (i = low; i < high; i++)
    {
      c[i] = a[i] + b[i];
      printf("Thread %d\t%d + %d = %d\n", threadnum, a[i], b[i], c[i]);
    }
  }
}