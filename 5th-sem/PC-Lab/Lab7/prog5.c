/* Demonstration of Blocking send and receive.*/
#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  int size, myrank, x[10], i, y[10];
  MPI_Status status;
  MPI_Request request;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  if (myrank == 0)
  {
    for (i = 0; i < 10; i++)
    {
      x[i] = 1;
      y[i] = 2;
    }
    MPI_Send(x, 10, MPI_INT, 1, 1, MPI_COMM_WORLD);
    //Blocking send will expect matching receive at the destination
    //In Standard mode, Send will return after copying the data to the system buffer. The
    //call will block if the buffer is not available or buffer space is not sufficient.
    MPI_Send(y, 10, MPI_INT, 1, 2, MPI_COMM_WORLD);
    // This send will be initiated and matching receive is already there so the program will not lead to deadlock
  }
  else if (myrank == 1)
  {
    MPI_Recv(x, 10, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
    //P1 will block as it has not received a matching send with tag 2
    for (i = 0; i < 10; i++)
      printf("Received Array x : %d\n", x[i]);
    MPI_Recv(y, 10, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    for (i = 0; i < 10; i++)
      printf("Received Array y : %d\n", y[i]);
  }
  MPI_Finalize();
  return 0;
}