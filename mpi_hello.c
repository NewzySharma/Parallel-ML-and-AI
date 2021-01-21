/* required MPI include file */ 
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define  MASTER		0

int main (int argc, char *argv[])
{
int   numtasks, rank, len;
char hostname[MPI_MAX_PROCESSOR_NAME];

// initialize MPI
MPI_Init(&argc, &argv);

// get number of tasks
MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

// get my rank 
MPI_Comm_rank(MPI_COMM_WORLD,&rank);

// this one is obvious 
MPI_Get_processor_name(hostname, &len);

//printf ("Number of tasks= %d My rank= %d Running on %s\n", numtasks,rank,hostname);
printf ("Hello from task %d on %s!\n", rank, hostname);

if (rank == MASTER)
   printf("MASTER: Number of MPI tasks is: %d\n",numtasks);

MPI_Finalize();

}

