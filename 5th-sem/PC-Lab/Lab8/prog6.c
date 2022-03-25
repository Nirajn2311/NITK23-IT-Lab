#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, x[15], y[3], i;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  if (myrank == 0)
  {
    printf("Enter 10 values into array x:\n");
    for (i = 0; i < 15; i++)
      scanf("%d", &x[i]);
  }
  MPI_Scatter(x, 3, MPI_INT, y, 3, MPI_INT, 0, MPI_COMM_WORLD);
  for (i = 0; i < 3; i++)
    printf("\nValue of y in process %d : %d\n", myrank, y[i]);
  printf("\nValue of y[3] in process %d : %d\n", myrank, y[3]);
  MPI_Finalize();
  return 0;
}