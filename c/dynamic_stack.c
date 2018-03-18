/* Programa de pila dinámica */
#include <stdio.h>
#include <stdlib.h>

/* Estructura auto-referenciada */
struct nodoPila{
  int dato;
  struct nodoPila *ptrSiguiente; /* apuntador a nodoPila */
};

typedef struct nodoPila NodoPila; /* alias de la estructura nodoPila */
typedef NodoPila* ptrNodoPila; /* alias para NodoPila* (apuntador a NodoPila)  */


/* prototipos */
void empujar(ptrNodoPila *ptrCima, int info);
int sacar( ptrNodoPila *ptrCima );
int estaVacia( ptrNodoPila ptrCima );
void imprimePila( ptrNodoPila ptrActual );
void instrucciones( void );


int main(){

  ptrNodoPila ptrPila = NULL; /* apunta al tope de la pila */
  int eleccion;
  int valor;

  instrucciones();
  printf("? ");
  scanf("%d",&eleccion);

  /* Mientras el usuario no intruduzca la opecion 3 */
  while (eleccion != 3) {

    switch( eleccion ){

      /*Empuja el valor dentro de la pila */
    case 1:
      printf("Introduzca un entero: ");
      scanf("%d", &valor);
      empujar( &ptrPila, valor );
      imprimePila( ptrPila );
      break;

      /* Saca el valor de la pila */ 
    case 2:
      /* Si la pila no está vacía */
      if( !estaVacia( ptrPila ) ){
        printf("El valor sacado es %d.\n", sacar(&ptrPila));
      }

      imprimePila( ptrPila );
      break;

    default:
      printf("Elección no válida.\n\n");
      instrucciones();
      break;
    }

    printf("? ");
    scanf("%d", &eleccion);
  }
  
  return 0;
}


/* Despliega las instrucciones del programa para el usuario */
void instrucciones( void ){
  printf("Introduzca su elección:\n"
         "1 para empujar un valor dentro de la pila\n"
         "2 para sacar un valor de la pila\n"
         "3 para terminar el programa\n");
}


/* Insertar un nodo en la cima de la pila */
void empujar(ptrNodoPila *ptrCima, int info){
  ptrNodoPila ptrNuevo; /* apuntador al nuevo nodo */
  ptrNuevo = malloc( sizeof(NodoPila) );

  /* Inserta el nodo en la cima de la pila */
  if( ptrNuevo != NULL ){
    ptrNuevo->dato = info;
    ptrNuevo->ptrSiguiente = *ptrCima;
    *ptrCima = ptrNuevo;
  }else{
    printf("Memoria insuficiente - no hubo inserción\n");
  }
}


/* Elimina un nodo de la cima de la pila */
int sacar( ptrNodoPila *ptrCima ){
  ptrNodoPila ptrTemp; /* apuntador a un nodo temporal */
  int valorElimn; /* valor del nodo */

  ptrTemp = *ptrCima;
  valorElimn = (*ptrCima)->dato;
  *ptrCima = (*ptrCima)->ptrSiguiente;
  free( ptrTemp );
  return valorElimn;
}


/* Imprime la pila */
void imprimePila( ptrNodoPila ptrActual ){

  /* Si la pila está vacía */
  if( ptrActual == NULL ){
    printf("La pila está vacía.\n\n");
  }else{
    printf("La pila es: \n");

    /* Mientras no sea el final de la pila */
    while( ptrActual != NULL ){
      printf("%d --> ", ptrActual->dato);
      ptrActual = ptrActual->ptrSiguiente;
    }
    printf("NULL\n\n");
  }
}


/* Devuelve 1 si la pila está vacía de lo contrario 0 */
int estaVacia( ptrNodoPila ptrCima ){
  return ptrCima == NULL;
}
