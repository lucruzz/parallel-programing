/*======================================================*/
/* Lucas Cruz                                           */
/* Engenharia de Computação - CEFET/RJ - UneD Petrópolis*/
/* Computação de Alto Desempenho                        */
/* MPI - Message Passing Interface                      */
/* Comunicação síncrona                                 */
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

  if (rank == 1){
  
    int dest = 2;
    int data = 77;
    
    MPI_Send( &data,            // endereço do dado a ser enviado
              1,                // número de elementos a serem enviados
              MPI_INT,          // tipo de dados dos elementos
              dest,             // rank do destinatário
              0,                // um número para "classificar" mensagens
              MPI_COMM_WORLD);  // comunicador MPI

    printf("Rank %d: sent %d to process %d\n", rank, data, dest);
  }

  if (rank == 2){
    
    MPI_Status st;
    int data;
    int rem = 1;
    
    MPI_Recv( &data,          // endereço que será utilizado para receber o dado
              1,              // número de elementos a serem lidos
              MPI_INT,        // tipo de dados dos elementos
              rem,            // rank do remetente (MPI_ANY_SOURCE para receber de qualquer rank)
              0,              // um número para "classificar" mensagens (MPI_ANY_TAG)
              MPI_COMM_WORLD, // comunicador MPI
              &st);           // informações sobre a mensagem (MPI_STATUS_IGNORE para ignorar)

    printf("Rank %d: received %d from process %d\n", rank, data, rem);
  }

  MPI_Finalize();

  return 0;
}
