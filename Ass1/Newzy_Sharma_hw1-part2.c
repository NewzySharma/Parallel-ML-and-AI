/* The master thread queries and prints selected environment information. */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nthreads, tid, procs, maxnum, inpar, dynamic, nested;

#pragma omp parallel
  {

  /* Obtain the thread number of the thread which is making this call: */
  tid = omp_get_thread_num();

  if (tid == 0) 
    {
    printf("Thread %d getting environment info...\n", tid);

    /* Please write the correct OpenMP routines: */
	/* Obtain the total number of processors of the node/machine: */
    procs = omp_get_num_procs();
	/* Obtain the number of threads available for the task: */
    nthreads = omp_get_num_threads();
	/* Obtain the maximum number of threads available totally: */
    maxnum = omp_get_max_threads();
	/* A routine to determine if this section is in parallel: */
    inpar = omp_in_parallel();
	/* A routine to determine if dynamic thread is enabled: */
    dynamic = omp_get_dynamic();
	/* determine if nested parallelism is enabled: */
    nested = omp_get_nested();

    /* Print environment information */
    printf("Number of processors = %d\n", procs);
    printf("Number of threads = %d\n", nthreads);
    printf("Max threads = %d\n", maxnum);
    printf("In parallel? = %d\n", inpar);
    printf("Dynamic threads enabled? = %d\n", dynamic);
    printf("Nested parallelism enabled? = %d\n", nested);

    }

  } 
  
}

/* Please find a place to comment which the parallel region is done. */
