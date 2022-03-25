#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define size 500000

int binary_search(int s, int e, int array[], int key, int flag)
{
  if (s > e)
  {
    return -1;
  }

  int a, b;
  int m = (s + e) / 2;

  if (array[m] == key)
  {
    return m;
  }
  else
  {
    #pragma omp task shared(a)
    {
      a = binary_search(s, m - 1, array, key, flag);
    }

    #pragma omp task shared(b)
    {
      b = binary_search(m + 1, e, array, key, flag);
    }

    #pragma omp taskwait
    if (a < b)
    {
      return b;
    }
    else
    {
      return a;
    }
  }

  return 0;
}

int comp(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main()
{
  int array[size], x, pos;
  double end, start;

  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % 1000;
  }
  qsort(array, size, sizeof(int), comp);

  printf("\n\nBEST CASE: Key searched is in middle position and found immediately.");
  x = array[size / 2];
  start = omp_get_wtime();
  pos = binary_search(0, size, array, x, 1);
  end = omp_get_wtime();
  printf("\nKey found at: %d", pos);
  printf("\nValue = %d", array[pos]);
  printf("\nSerial runtime : %lf", end - start);
  start = omp_get_wtime();
  pos = binary_search(0, size, array, x, 0);
  end = omp_get_wtime();
  printf("\n\nKey found at: %d", pos);
  printf("\nValue = %d", array[pos]);
  printf("\nParallel runtime : %lf", end - start);

  printf("\n\n\nWORST CASE: Key searched is not present in array.");
  x = -1000;
  start = omp_get_wtime();
  pos = binary_search(0, size, array, x, 1);
  end = omp_get_wtime();
  printf("\nKey found at: %d", pos);
  printf("\nKey = %d", x);
  printf("\nSerial runtime : %lf", end - start);
  start = omp_get_wtime();
  pos = binary_search(0, size, array, x, 0);
  end = omp_get_wtime();
  printf("\n\nKey found at: %d", pos);
  printf("\nKey = %d", x);
  printf("\nParallel runtime : %lf", end - start);

  printf("\n\n\nAVERAGE CASE: Random key inputted by user.");
  printf("\nEnter key to be searched: ");
  scanf("%d", &x);
  start = omp_get_wtime();
  pos = binary_search(0, size, array, x, 1);
  end = omp_get_wtime();
  printf("\nKey found at: %d", pos);
  printf("\nValue = %d", array[pos]);
  printf("\nSerial runtime : %lf", end - start);
  start = omp_get_wtime();
  pos = binary_search(0, size, array, x, 0);
  end = omp_get_wtime();
  printf("\n\nKey found at: %d", pos);
  printf("\nValue = %d", array[pos]);
  printf("\nParallel runtime : %lf\n", end - start);
}