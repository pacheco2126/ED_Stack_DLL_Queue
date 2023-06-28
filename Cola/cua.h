#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define CUA_NO_CREADA 3
#define CUA_BUIDA 4
#define CUA_PLENA 5

typedef struct Cua
{
	int* data;
	int indexOut, indexIn, maxElems;
}Cua;

int Crear(Cua* ac, int size);
int Encuar(Cua* ac, int elem);
int Desencuar(Cua* ac);
int Cap(Cua ac, int* elem);
int EsBuida(Cua c, bool* b);
int EsPlena(Cua c, bool* b);
int Destruir(Cua* ac);