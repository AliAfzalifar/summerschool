#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    // write the control structure as described in the exercise
    // and run the code with different values for i

    int N = 3, k;

    for (k=0; k<=N+1 ;k++) {
      
      switch(k) {
      case 1:
	printf("case1 %d \n", k);
	break;
      case 2:
	printf("case2 %d \n", k);
	break;
      case 3:
	printf("case3 %d \n", k);
	break;
      default:
	printf("default %d \n", k);
	break;
      }
    }
      

    return 0;
}
