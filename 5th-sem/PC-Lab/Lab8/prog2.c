#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, x;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  printf("Before boradcast :Value of x in process %d : %d\n", myrank, x);
  if (myrank == 0)
  {
    scanf("%d", &x);
  }
  MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
  printf("After Broadcast: Value of x in process %d : %d\n", myrank, x);
  MPI_Finalize();
  return 0;
}