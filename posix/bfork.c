#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

  int *valor = malloc(sizeof(int));
  pid_t k;
  *valor = 0;
  k = fork();
  if(k > 0){
      *valor = 13;
    }else{
    *valor = 5;
  }
  printf("%ld: %d\n", (long)getpid(), *valor);
  free(valor);
  return 0;
}
