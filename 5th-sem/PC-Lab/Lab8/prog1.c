#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, x, i;
  MPI_Status status;
  MPI_Request request;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  if (myrank == 0)
  {
    x = 10;
    printf("Process %d of %d, Value of x is %d sending the value x\n", myrank, size, x);
    MPI_Isend(&x, 1, MPI_INT, 1, 2, MPI_COMM_WORLD, &request); // tag is different at receiver
    MPI_Wait(&request, &status);
  }
  else if (myrank == 1)
  {
    printf("Value of x is : %d before receive\n", x);
    MPI_Irecv(&x, 1, MPI_INT, 0, 20, MPI_COMM_WORLD, &request);
    printf("Receive returned immediately\n");
    MPI_Wait(&request, &status);
  }
  if (myrank == 1)
    printf("Value of x is : %d after receive\n", x);
  MPI_Finalize();
  return 0;
}