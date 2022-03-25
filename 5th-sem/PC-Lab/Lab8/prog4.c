#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, x = 10, y[5], i;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Gather(&x, 1, MPI_INT, y, 1, MPI_INT, 0, MPI_COMM_WORLD); // Value of x at each process is copied to array y in Process 0 if (myrank == 0)
  {
    for (i = 0; i < size; i++)
      printf("\nValue of y[%d] in process %d : %d\n", i, myrank, y[i]);
  }
  MPI_Finalize();
  return 0;
}