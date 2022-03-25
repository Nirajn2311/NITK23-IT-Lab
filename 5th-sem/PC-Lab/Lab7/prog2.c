#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int size, myrank, x, i;
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  if (myrank == 0)
  {
    x = 10;
    printf("Process %d of %d, Value of x is %d sending the value x\n", myrank, size, x);
    MPI_Send(&x, 1, MPI_INT, 1, 55, MPI_COMM_WORLD);
  }
  else if (myrank == 1)
  {
    printf("Value of x is : %d before receive\n", x);
    MPI_Recv(&x, 1, MPI_INT, 0, 55, MPI_COMM_WORLD, &status);
    printf("Process %d of %d, Value of x is %d\n", myrank, size, x);
    printf("Source %d Tag %d \n", status.MPI_SOURCE, status.MPI_TAG);
  }
  MPI_Finalize();
  return 0;
}

// #include <mpi.h>
// #include <stdio.h>
// #include <string.h>

// int main(int argc, char *argv[])
// {
//   int size, myrank, x, i;
//   char inp[5] = "PCLAB", op[30] = "TEST";
//   MPI_Status status;
//   MPI_Init(&argc, &argv);
//   MPI_Comm_size(MPI_COMM_WORLD, &size);
//   MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
//   if (myrank == 0)
//   {
//     printf("Process %d of %d, Value of inp is %s sending the value inp\n", myrank, size, inp);
//     MPI_Send(&inp, strlen(inp), MPI_CHAR, 1, 55, MPI_COMM_WORLD);
//   }
//   else if (myrank == 1)
//   {
//     printf("Value of op is : %s before receive\n", op);
//     MPI_Recv(&op, 30, MPI_CHAR, 0, 55, MPI_COMM_WORLD, &status);
//     printf("Process %d of %d, Value of op is %s\n", myrank, size, op);
//     printf("Source %d Tag %d \n", status.MPI_SOURCE, status.MPI_TAG);
//   }
//   MPI_Finalize();
//   return 0;
// }

// #include <mpi.h>
// #include <stdio.h>
// #include <string.h>

// int main(int argc, char *argv[])
// {
//   int size, myrank, x, i;
//   int arr[5] = {1, 2, 33, 24, 50}, oparr[5] = {0, 0, 0, 0, 0};
//   MPI_Status status;
//   MPI_Init(&argc, &argv);
//   MPI_Comm_size(MPI_COMM_WORLD, &size);
//   MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
//   if (myrank == 0)
//   {
//     printf("Process %d of %d, Value of arr is:\n", myrank, size);
//     for(i = 0; i < 5; i++)
//     {
//       printf("Process %d of %d, Value of arr[%d] is %d\n", myrank, size, i, arr[i]);
//     }
//     printf("Process %d of %d, sending the value arr\n", myrank, size);
//     MPI_Send(arr, 5, MPI_INT, 1, 55, MPI_COMM_WORLD);
//   }
//   else if (myrank == 1)
//   {
//     printf("Process %d of %d, Value of oparr before receive\n", myrank, size);
//     for(i = 0; i < 5; i++)
//     {
//       printf("Process %d of %d, Value of op[%d] is %d\n", myrank, size, i, oparr[i]);
//     }
//     MPI_Recv(oparr, 5, MPI_INT, 0, 55, MPI_COMM_WORLD, &status);
//     printf("Process %d of %d, Value of oparr is:\n", myrank, size);
//     for(i = 0; i < 5; i++)
//     {
//       printf("Process %d of %d, Value of op[%d] is %d\n", myrank, size, i, oparr[i]);
//     }
//     printf("Source %d Tag %d \n", status.MPI_SOURCE, status.MPI_TAG);
//   }
//   MPI_Finalize();
//   return 0;
// }