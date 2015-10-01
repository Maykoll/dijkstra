#ifndef nodo_h
#include "nodo.h"
#define nodo_h
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MaxNodos 10
//variables globales 
Tnodo *Lista[MaxNodos]; //lista de adyacencia
int marca[MaxNodos]; //visitados 
int predecesores[MaxNodos]; //ruta
float d[MaxNodos]; // distancia - peso 
int Num_Vertices; //numero de vertices
int tipo; //1 no dirigido, 0 dirigido


//Inicializa la lista de adyacencia a NULL 
void init() {
    int i; 
    for (i = 0; i < MaxNodos; i++)
        Lista[i] = NULL;     
}

//Muestra la lista de adyacencia
void mostrar_lista_adyacencia () {
   Tnodo *q;
   int i;
   
   for (i = 0; i < Num_Vertices; i++) {
      if (Lista[i] != NULL) {
         q = Lista[i];
         printf ("vertice %d: ", i);
         while (q) {
            printf ("%d ", q->etiqueta);
            q = q->sig;
         }
         printf("\n");
      }
   }
}
//imprime estado de los verices
void mostrar_estado_inicial_nod () {
   Tnodo *q;
   int i;
   
   for (i = 0; i < Num_Vertices; i++) {
      if (Lista[i] != NULL) {
         q = Lista[i];
         printf ("vertice %d: ", i);
         while (q) {
            printf ("%d ", q->peso);
            printf ("%d \n", q->color);
            q = q->sig;
         }
         printf("\n");
      }
   }
}

//falta ***********************************************
int main () {

return 0;    
}
