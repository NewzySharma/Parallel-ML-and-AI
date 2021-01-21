// HW1 - Part 3
// Please implement OpenMP directives for this code.

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define CHUNKSIZE   10
#define N       100

int main (int argc, char *argv[]) 
{
int nthreads, tid, i, chunk;
float a[N], b[N], c[N];

/* Some initializations */
for (i=0; i < N; i++)
  a[i] = b[i] = i * 1.0;
chunk = CHUNKSIZE;

// Parallelize the following whole part with OpenMP directives, 
// and specify shared variables and private variable
  {
  omp_id = omp_get_thread_num();
  if (omp_id == 0)
    {
    nthreads = omp_get_num_threads();
    }
 
 
  // parallelize the for loop using dynamic schedule
  for (i=0; i<N; i++)
    {
    tmp = 2.0* a[i];
	a[i] = tmp;
	c[i] = a[i] + b[i];
    }

  }  

