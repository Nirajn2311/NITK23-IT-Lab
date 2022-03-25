#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
  struct timeval TimeValue_Start;
  struct timezone TimeZone_Start;
  struct timeval TimeValue_Final;
  struct timezone TimeZone_Final;
  long time_start, time_end;
  double time_overhead;

  const int N = 5000;
  int a[N], b[N], c[N];
  for (int i = 0; i < N; i++)
  {
    a[i] = rand();
    b[i] = rand();
  }
  gettimeofday(&TimeValue_Start, &TimeZone_Start);
#pragma omp parallel num_threads(10)
#pragma omp for schedule(runtime)
  for (int i = 0; i < N; i++)
  {
    c[i] = a[i] + b[i];
  }
  gettimeofday(&TimeValue_Final, &TimeZone_Final);
  time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
  time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
  time_overhead = (time_end - time_start) / 1000000.0;
  printf("\n\t\t Time in Seconds (T) : %lf\n\n", time_overhead);
  return 0;
}
