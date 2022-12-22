/*======================================================*/
/* Lucas Cruz                                           */
/* Engenharia de Computação - CEFET/RJ - UneD Petrópolis*/
/* Computação de Alto Desempenho                        */
/* MPI - Message Passing Interface                      */
/* Hello World                                          */
/* Compilar: mpicc hello-mpi.c -o hello                 */
/* Executar: mpirun --oversubscribe -np 3 ./hello       */
/*======================================================*/

#include <stdio.h>
#include <mpi.h>

int main(int argc, char ** argv){

  int size, rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0){
    printf("number of process: %d\n", size);
  }

  printf("Hello world from rank %d!\n", rank);

  MPI_Finalize();

  return 0;
}
