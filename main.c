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
    //q->color    = 0; //color blanco
    if (Lista[Vorigen-1] != NULL)
       q->sig = Lista[Vorigen-1];
    Lista[Vorigen-1] = q; 
}

void liberar_lista (void) {
   Tnodo *q;
   int i;
   for (i = 0; i <  Num_Vertices; i++) {
      if (Lista[i] != NULL) {
         while (Lista[i] != NULL) {
            q = Lista[i];
            Lista[i] = Lista[i]->sig;
            free(q);
         }
      } //--fin si 
   } //--fin for 
}

//Carga el grafo desde un fichero 
void cargar_grafo (char *fn) {
  FILE *fp;
  int v_in, v_fn; //vertice inicial y final
  float peso;
  if ((fp = fopen ("grafo.txt", "r")) == NULL) {
       printf ("No se puede abrir el archivo\n", fn);
       exit(0);         
   }
   fscanf (fp, "%d\n", &tipo); //tipo es una vble global
   fscanf (fp, "%d\n", &Num_Vertices); //Num_Vertices es una vble global 
   while (!feof(fp)){
         fscanf(fp, "%d %d %f\n", &v_in, &v_fn, &peso);
         inserta(v_in, v_fn, peso);
         inserta (v_fn, v_in, peso);
   }
   fclose (fp);
} 

//falta ***********************************************
// funcion que carge archivo y muchas cosas mas
int main () {

return 0;    
}
