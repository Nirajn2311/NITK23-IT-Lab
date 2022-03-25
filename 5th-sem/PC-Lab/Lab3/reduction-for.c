#include <omp.h>
#include <stdio.h>
int main(void)
{
  int n = 20, dsum = 0, tid, a[20], sum = 0, i;
  for (i = 0; i < n; i++)
  {
    a[i] = i;
    dsum = dsum + i;
  }
#pragma omp parallel num_threads(6)
  {
    int tid = omp_get_thread_num();
#pragma omp for private(i) schedule(static, 5) reduction(+: sum)
    for (i = 0; i < n; i++)
      sum = sum + a[i];
  }
  printf("sum= %d\n", sum);

  return 0;
}