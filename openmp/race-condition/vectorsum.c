#include <stdio.h>
#include <omp.h>

#define NX 10

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
    printf("Arithmetic sum formula (exact):                     %ld\n",sumex);

    sum = 0.0;
#pragma omp parallel default(shared) private(i)
    {
#pragma omp for
      for (i = 0; i < NX; i++) {
	sum += vecA[i];
      }
    }       
    printf("Sum with data race:                                 %ld\n",sum);
    
    sum = 0.0;
#pragma omp parallel default(shared) private(i)
    {
      #pragma omp for
      for (i = 0; i < NX; i++) {	
        #pragma omp critical(crit_1)
	{
        sum += vecA[i];
	// this is just to check how critical works
	//if (i==4) {printf("thred num: %d\n", omp_get_thread_num());}
	}
      }
    }               
    printf("Sum with critical:                                  %ld\n",sum);

    sum = 0.0;
#pragma omp parallel default(shared) private(i, psum)
    {
     psum = 0.0; 
     #pragma omp for      
      for (i = 0; i < NX; i++) {
        psum += vecA[i];
      }
     #pragma omp critical(crit_2)
      sum += psum;
      if (omp_get_thread_num()==0) {printf("thred num: %d\n psum: %ld\n",omp_get_thread_num(),psum);}
      if (omp_get_thread_num()==1) {printf("thred num: %d\n psum: %ld\n",omp_get_thread_num(),psum);}
    }
    printf("Sum using private variable and critical section:    %ld\n",sum);
    
    sum = 0.0;
#pragma omp parallel shared(vecA)  private(i) reduction(+:sum)
    {
      printf("num of threds : %d\n ",omp_get_num_threads());
#pragma omp for      
      for (i = 0; i < NX; i++) {
        sum += vecA[i];
      }
    }
    printf("Sum with reduction:    %ld\n",sum);
    printf("num of threds : %d\n ",omp_get_num_threads());
    return 0;
}
