#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  printf("Process %d of %d, Hello World\n", myrank, size);
  MPI_Finalize();
  return 0;
}