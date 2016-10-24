#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lautnode * ListaAut;
typedef struct lautnode{
    char comp[15];
    ListaAut next;
}ListaAut_node;

typedef struct {
	int porto;
	char scheduling[10];
	int nthreads;
	ListaAut listaAll;

}Config;

int le_ficheiro();