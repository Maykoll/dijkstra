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

//Inserta los vertices en la lista de adyacencia 
void inserta (int Vorigen, int Vfinal, float peso) {
    Tnodo *q;
    q = (Tnodo*) malloc (sizeof(Tnodo) * 1);
    if (!q) return; 
    q->etiqueta = Vfinal-1;
    q->peso     = peso;
    q->sig      = NULL;
    q->color    = 0; //color blanco
    if (Lista[Vorigen-1] != NULL)
       q->sig = Lista[Vorigen-1];
    Lista[Vorigen-1] = q; 
}


//falta ***********************************************
// funcion que carge archivo y muchas cosas mas
int main () {

return 0;    
}
