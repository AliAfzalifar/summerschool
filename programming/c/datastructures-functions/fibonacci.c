#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare array and loop variable
    int f[20];
    int i;

    // initialize necessary array elements and write the for loop
    f[0]= 0;
    f[1]= 1;
    printf("First 20 Fibonacci numbers are:\n");
    for (i = 0; i < 20; i++) {
      switch(i) {
      case 0:
	printf("%d \n", f[i]);
	break;
      case 1:
	printf("%d \n", f[i]);
	break;
      default:
        f[i] = f[i-1]+f[i-2];
        printf("%d \n", f[i]);
	break;
      }
    }

    printf("\n");

    return 0;
}
