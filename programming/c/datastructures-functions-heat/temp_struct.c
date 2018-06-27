#include <stdio.h>
#include <stdlib.h>
#include "pngwriter.h"

#define NX 258
#define NY 258

typedef struct {
  int nx,ny;
  float dx, dy;
  float da;
  double T[NX][NY];
  double L[NX][NY];

} temp_field;

void init(temp_field *ptr) {
  int i,j;

  for (i = 1; i < NX - 1; i++) {
    for (j = 1; j < NY - 1; j++) {
      ptr->T[i][j] = 0.0;
        }
    }

  for (i = 0; i < NX; i++) {
        ptr->T[i][0] = 20.0;
        ptr->T[i][NY - 1] = 70.0;
    }
    
    for (j = 0; j < NY; j++) {
        ptr->T[0][j] = 85.0;
        ptr->T[NX - 1][j] = 5.0;
    }
  
}

void laplacian(temp_field *ptr) {
  int i,j;
  for (i = 0; i < NX; i++) {
    ptr->L[i][0] = ptr->L[i][NY - 1]= 0.0;
  }
  for (j = 0; i < NY; j++) {
    ptr->L[0][j] = ptr->L[NX - 1][j] = 0.0;
  }
  for (j=1; j<(NY-1) ; j++) {
    for (i=1; i<(NX-1) ; i++) {
      ptr->L[i][j]= (ptr->T[i-1][j]-2*ptr->T[i][j]+ptr->T[i+1][j])/(ptr->dx*ptr->dx) + (ptr->T[i][j-1]-2*ptr->T[i][j]+ptr->T[i][j+1])/(ptr->dy*ptr->dy);
    }
  }

}


int main(void)
{

  temp_field dom1;
    
  //temp_field *ptr;

  dom1.dx = 0.01;
  dom1.dy = 0.01;
 
  init(&dom1);
  laplacian(&dom1);
  
  save_png((double *) dom1.T, NX, NY, "init_temp.png", 'c');
  save_png((double *) dom1.L, NX, NY, "Lap_temp.png", 'c');
 
}
