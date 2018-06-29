#include <stdio.h>

void add_func(float *ptr_flo, int *ptr_int) {
  //float *ptr_flo;
  //int   *ptr_int;
  
  (*ptr_int)++;
  //(*ptr_flo)++;
  *ptr_flo = 3*(*ptr_flo);
}


int main(int argc, char *argv[])
{
    
  float ptr_flo = 3.5;
  int   ptr_int = 1;

  add_func(&ptr_flo, &ptr_int);

  printf("%f  %d \n ", ptr_flo,ptr_int);

    return 0;
}
