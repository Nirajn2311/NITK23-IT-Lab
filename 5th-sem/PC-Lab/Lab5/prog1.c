#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int main(void)
{
  struct timeval TimeValue_Start;
  struct timezone TimeZone_Start;
  struct timeval TimeValue_Final;
  struct timezone TimeZone_Final;
  long time_start, time_end;
  double time_overhead;
  double pi, x;
  int i, N;
  pi = 0.0;
  N = 1000;
  gettimeofday(&TimeValue_Start, &TimeZone_Start);
  for (i = 0; i <= N; i++)
  {
    x = (double)i / N;
    pi += 4 / (1 + x * x);
  }
  gettimeofday(&TimeValue_Final, &TimeZone_Final);
  time_start = TimeValue_Start.tv_sec * 1000000 + TimeValue_Start.tv_usec;
  time_end = TimeValue_Final.tv_sec * 1000000 + TimeValue_Final.tv_usec;
  time_overhead = (time_end - time_start) / 1000000.0;
  printf("\n\n\tTime in Seconds (T) : %lf\n", time_overhead);
  pi = pi / N;
  printf("\n \tPi is %f\n\n", pi);
}