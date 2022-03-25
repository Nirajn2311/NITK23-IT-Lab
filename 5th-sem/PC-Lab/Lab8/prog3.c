#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, i, x, y;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  x = myrank+1; // Note the value of x in each process.
  MPI_Reduce(&x, &y, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  if (myrank == 0)
  {
    printf("Value of y after reduce : %d\n", y);
  }
  MPI_Finalize();
  return 0;
}