#include <omp.h>
#include <stdio.h>

int fibo(int n);

int main(void)
{
  int n, fib;
  double t1, t2;
  printf("Enter the value of n:\n");
  scanf("%d", &n);
  t1 = omp_get_wtime();
#pragma omp parallel shared(n)
  {
#pragma omp single
    {
      fib = fibo(n);
    }
  }
  t2 = omp_get_wtime();
  printf("Fib is %d\n", fib);
  printf("Time taken is %f s \n", t2 - t1);
  return 0;
}

int fibo(int n)
{
  int a, b;
  if (n < 2)
    return n;
  else
  {
#pragma omp task shared(a)
    {
      printf("Task Created by Thread %d\n", omp_get_thread_num());
      a = fibo(n - 1);
      printf("Task Executed by Thread %d \ta=%d\n", omp_get_thread_num(), a);
    }
#pragma omp task shared(b)
    {
      printf("Task Created by Thread %d\n", omp_get_thread_num());
      b = fibo(n - 2);
      printf("Task Executed by Thread %d \tb=%d\n", omp_get_thread_num(), b);
    }
#pragma omp taskwait
    return a + b;
  }
}