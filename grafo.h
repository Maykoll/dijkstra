#ifndef SRDIO_H
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdlib_h
#endif

#ifndef nodo_h
#include "nodo.h"
#define nodo_h
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif



void inicializar_grafo(){
  
  int matriz[tam][tam]={	{ 0, 3, 1, 0, 0, 0, 0, 0},  
		     		{ 3, 0, 0, 1, 0, 0, 5, 0},
 		    		{ 1, 0, 0, 2, 0, 5, 0, 0},
		 		{ 0, 1, 2, 0, 4, 2, 0, 0},
				{ 0, 0, 0, 4, 0, 0, 2, 1},
				{ 0, 0, 5, 2, 0, 0, 0, 3},
				{ 0, 5, 0, 0, 2, 0, 0, 0},
				{ 0, 0, 0, 0, 1, 3, 0, 0}
				
				}; //matriz incompleta
}
					   	 
