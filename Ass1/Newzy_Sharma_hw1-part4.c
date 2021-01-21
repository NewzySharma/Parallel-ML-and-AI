/** This coder was programmed for dot-product of two vectors. **/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/* Define length of dot product vectors */
#define VECLEN 100

int main (int argc, char* argv[])
{
int i,len=VECLEN;
double *a, *b;
double sum, tsum = 0.0;
int numtasks, taskid;

MPI_Status status;
// Initializing MPI
MPI_Init(&argc, &argv);
MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

len = VECLEN * numtasks;

if(taskid == 0)
	printf("Starting MPI for dot-product of a and b on %d processors \n", numtasks);

/* Assign storage for dot product vectors */
a = (double*) malloc (len*sizeof(double));
b = (double*) malloc (len*sizeof(double));

/* Initialize dot product vectors */
for (i=0; i<len; i++) {
  a[i]=1.0;
  b[i]=a[i];
  }

/* Perform the dot product */
sum = 0.0;
for (i=0; i<len; i++) 
  {
    sum += (a[i] * b[i]);
  }


MPI_Reduce(&sum, &tsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
if(taskid == 0){
  printf ("“Done. MPI execution to obtain global sum=  %f \n", tsum);
}

MPI_Finalize();
free (a);
free (b);
}   
