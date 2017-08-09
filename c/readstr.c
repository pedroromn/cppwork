#include <stdio.h>

#define MAXLON 80

int main(int argc, char const *argv[]){

  char cadena[MAXLON +1];
  printf("Escribe: ");
  scanf("%[^\n]", cadena);
  printf("La cadena leida es: \"%s\"\n", cadena);
  return 0;
}
