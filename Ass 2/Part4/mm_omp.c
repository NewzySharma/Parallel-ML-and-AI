/** Matrix Multiply - OpenMp Implementation **/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NRA 500 			/* number of rows in matrix A */
#define NCA 500			/* number of columns in matrix A */
#define NRB 500  		/* number of rows in matrix B */
#define NCB 300   		/* number of columns in matrix B */
#define NRC 500  		/* number of rows in matrix C */
#define NCC 300   		/* number of columns in matrix C */

int main (int argc, char *argv[])
{
int	tid, nthreads, i, j, k, chunk;
double	a[NRA][NCA],           /* matrix A to be multiplied */
	b[NCA][NCB],           /* matrix B to be multiplied */
	c[NRA][NCB];           /* result matrix C */
double start;
double end;

chunk = 10;                    /* set loop iteration chunk size */
omp_set_num_threads(8);

/*** Spawn a parallel region explicitly scoping all variables ***/
#pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid,i,j,k)
  {
  tid = omp_get_thread_num();
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
    printf("Starting matrix multiple example with %d threads\n",nthreads);
    printf("Initializing matrices...\n");
    }
  /*** Initialize matrices ***/
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[i][j]= i+j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[i][j]= i*j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[i][j]= 0;

  /*** Do matrix multiply sharing iterations on outer loop ***/

	start = omp_get_wtime();
  printf("Thread %d starting matrix multiply...\n",tid);
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NRA; i++)
    {
   // printf("Thread=%d did row=%d\n",tid,i);
    for(j=0; j<NCB; j++)
      for (k=0; k<NCA; k++)
        c[i][j] += a[i][k] * b[k][j];
    }
  }   /*** End of parallel region ***/
	end = omp_get_wtime();
	printf("Elapsed time is %f seconds\n", end - start);
	printf ("Done.\n");

}
