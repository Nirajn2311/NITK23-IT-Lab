#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, x, i, y;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  if (myrank == 0)
  {
    x = 0;
    do
    {
      MPI_Recv(&x, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      printf("Process %d of %d, Value of x is %d : source %d tag %d error %d\n\n", myrank, size, x, status.MPI_SOURCE, status.MPI_TAG, status.MPI_ERROR);
    } while (x > 0);
  }
  else if (myrank > 0)
  {
    y = myrank % 5;
    printf("Process %d of %d, Value of y is %d : sending the value y\n", myrank, size, y);
    MPI_Send(&y, 1, MPI_INT, 0, (10 + myrank), MPI_COMM_WORLD);
  }
  MPI_Finalize();
  return 0;
}

// MPI_ANY_SOURCE
// - In a receive, accept a message from anyone.
// MPI_ANY_TAG
// - In a receive, accept a message with any tag value.