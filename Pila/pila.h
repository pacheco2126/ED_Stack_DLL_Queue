#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Pila
{
	int maxElems;
	int numElems;
	int* data;
	
}Pila;

Pila Crear(int size);
int Cim(Pila p);
void Apilar(Pila* ap, int elem);
void Desapilar(Pila* ap);
bool EsBuida(Pila p);
bool EsPlena(Pila p);
void Destruir(Pila* ap);
void permutacionNelems(Pila* ap, int elems);
void repetirNveces(Pila* ap, int rep);
void duplicar(Pila* ap);
