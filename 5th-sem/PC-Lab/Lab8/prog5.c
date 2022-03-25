#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, x[8], y[3], i;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  if (myrank == 0)
  {
    printf("Enter 8 values into array x:\n");
    for (i = 0; i < 8; i++)
      scanf("%d", &x[i]);
  }
  MPI_Scatter(x, 2, MPI_INT, y, 2, MPI_INT, 0, MPI_COMM_WORLD);
  for (i = 0; i < 2; i++)
    printf("\nValue of y in process %d : %d\n", myrank, y[i]);
  MPI_Finalize();
  return 0;
}