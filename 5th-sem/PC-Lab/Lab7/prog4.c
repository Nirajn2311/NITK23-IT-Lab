#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  int size, myrank, x[50], y[50], i;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  printf("Verifying mistag send and receive\n");
  if (myrank == 0)
  {
    for (i = 0; i < 50; i++)
      x[i] = i + 1;
    MPI_Send(x, 10, MPI_INT, 1, 10, MPI_COMM_WORLD);
  }
  else if (myrank == 1)
  {
    MPI_Recv(y, 10, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
    printf(" Process %d Recieved data from Process %d\n", myrank, status.MPI_SOURCE);
    for (i = 0; i < 10; i++)
      printf("%d\t", y[i]);
  }
  MPI_Finalize();
  return 0;
}