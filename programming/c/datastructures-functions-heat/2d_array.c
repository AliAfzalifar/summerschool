#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define NX 5
#define NY 5

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
    //#error Define the array
    
    float array[NX][NY];
      

    // Initialize first the zeros
    //#error Initialize the zeros for interior

    
    for (i=0; i<NX ; i++) {
      array[i][0]=20.0;
      array[i][NY-1]=70.0;
    }

    for (j=0; j<NY ; j++) {
      array[0][j]=85.0;
      array[NX-1][j]=5.0;
    }


    for (j=1; j<(NY-1) ; j++) {
      for (i=1; i<(NX-1) ; i++) {
	array[i][j]=0.0;
      }
    }

    for (i=0; i<NX ; i++) {
      for (j=0; j<NY ; j++) {
	printf("\t  %f \t ", array[i][j]);
      }
      printf(" \n");
    }

    
    // Initial conditions for left and right
    //#error add boundary conditions for left and right

    // and top and bottom boundaries
    //#error add boundary conditions for top and bottom

    return 0;
}
