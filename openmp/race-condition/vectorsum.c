#include <stdio.h>
#include <omp.h>

#define NX 5678

int main(void)
{
    long vecA[NX];
    long sum, psum, sumex;
    int i;

    /* Initialization of the vectors */
    for (i = 0; i < NX; i++) {
        vecA[i] = (long) i + 1;
    }

    sumex = (long) NX * (NX + 1) / ((long) 2);
    printf("Arithmetic sum formula (exact):                  %ld\n",
           sumex);

    sum = 0.0;
    /* TODO: Parallelize computation */
#pragma omp parallel shared(vecA)  private(i) reduction(+:sum)
    {
      printf("thred num: %d\n", omp_get_thread_num());
#pragma omp for      
      for (i = 0; i < NX; i++) {
        sum += vecA[i];
      }
    }
    printf("Sum_par: %ld\n", sum);
    printf("Sum_ref: %ld\n", (long) NX*(NX+1)/2);
    return 0;
}
