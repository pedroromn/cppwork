#include <stdio.h>
#include <stdlib.h>

int main(){

  int a = 7;   /* a es un entero */
  int *ptrA;   /* ptrA es un apuntador a un entero  */

  ptrA = &a;

  printf("La dirección de a %p"
         "\nEl valor de ptrA es %p", &a, ptrA);

  printf("\n");
  return 0;
}
