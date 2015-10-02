#ifndef nodo_h
#include "nodo.h"
#define nodo_h
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MaxNodos 10
#define Num_Vertices 8
#define tipo 0

//variables globales 
Tnodo *Lista[MaxNodos]; //lista de adyacencia
int marca[MaxNodos]; //visitados 
int predecesores[MaxNodos]; //ruta
float d[MaxNodos]; // distancia - peso 
//int Num_Vertices; //numero de vertices
//int tipo; //1 no dirigido, 0 dirigido


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
            //printf ("%d \n", q->color);
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
  if ((fp = fopen ("G.txt", "r")) == NULL) {
       printf ("el archivo no existe\n", fn);
       exit(0);         
   }
   while (!feof(fp)){
         fscanf(fp, "%d %d %f\n", &v_in, &v_fn, &peso);
         inserta(v_in, v_fn, peso);
         inserta (v_fn, v_in, peso);
   }
   fclose (fp);
} 

float return_peso (int origen, int destino) {
   Tnodo *p;
   int encontrado;
   
   encontrado = 0;
   p = Lista[origen];
   while (p != NULL && !encontrado) {
      if (p->etiqueta == destino)
        encontrado = 1;
      else
        p = p->sig;
   }
   return p->peso;
}


int menor_valor() {
   int i, verticeMenor;
   float menor;
   menor = INT_MAX;
   for (i = 0; i < Num_Vertices; i++) {
      if (marca[i] == 0 )
         if (menor > d[i]) {
            menor = d[i];
            verticeMenor = i;
         }
   } // fin for
   return verticeMenor; 
}

//falta ***********************************************
// funcion que carge archivo y muchas cosas mas

/* Dijkstra */
void dijkstra (int origen, int destino)
{
   int i, last, x;
   Tnodo *p;
   // inicializacion
   for (i = 0; i < MaxNodos; i++) {
      d[i] = INT_MAX; //"infinito"
      marca[i] = 0;
      predecesores[i] = -1;
   }
   // --
   d[origen] = 0;
   marca[origen] = 1;
   last = origen;
   while (marca[destino] == 0) { //hasta que no lleguemos al destino
      p = Lista[last];
      while (p != NULL){   //para todos los nodos adyacendes
          if (marca[p->etiqueta] == 0) //si no ha sido visitado
	          if (d[p->etiqueta] > d[last] + return_peso(last, p->etiqueta))
              {
	              d[p->etiqueta] = d[last] + return_peso(last, p->etiqueta);
	              predecesores[p->etiqueta] = last;
	          } // fin si
           p = p->sig;
      } // fin mientras
      x = menor_valor();    
      marca[x] = 1;
      last = x;
   } // fin mientras
}

/// Imprime la ruta por pantalla 
void ImprimirCamino(int v) {
   if (v != -1)
      ImprimirCamino(predecesores[v]);
   if (v != -1) 
      printf("%d ",v+1);
}

// Menu de opciones 
int menu() {
    int opcion;
    do {
        printf ("\n\nPresione 1 para calcular ruta o 0 para salir:  ");   
        //printf ("Opcion: ");
        scanf("%d", &opcion); 
    }while (opcion < 0 || opcion > 1);
    return opcion;
}

// Funcion principal 
int main () {
    char file[25]; 
    int origen, destino;
    int salir = 0;
    printf("inicializando el grafo\n\n");
    init();
    cargar_grafo(file);
    mostrar_lista_adyacencia(); 
    //mostrar_estado_inicial_nod ();
    do {
        switch(menu()) {
            case 0:
                 salir = 1;
                 break;
            case 1:
                  do {
                      printf ("\nVertice origen: "); 
					  scanf("%d", &origen);
                      printf ("\nVertice destino: "); 
					  scanf("%d", &destino);
					  printf ("\nLa ruta mas corta es:  \n"); 
                      if (origen < 1 || origen > MaxNodos || destino < 1 || destino > MaxNodos)
                           printf ("El valor tiene que estar entre 1 y ",Num_Vertices);
                  }while (origen < 1 || origen > Num_Vertices || destino < 1 || destino > Num_Vertices);    
                  dijkstra(origen-1, destino-1);
                  ImprimirCamino(destino-1);
                  break;          
        }; 
    }while(!salir);    
    liberar_lista();
}
