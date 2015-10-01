#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdlib_h
#endif

typedef struct nodo_ {
    int etiqueta;
    float peso;
    struct nodo_ *sig;
    char color;
}Tnodo;
