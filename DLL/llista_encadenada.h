#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR_NO_EXISTEIX 1
#define ES_FINAL 2
#define ERROR_DESTRUCCION 3
#define ERROR_PDI_NEXT_OR_PREV 4
typedef struct node* pNode;

typedef struct node {
    int data;
    pNode prev;
    pNode Next;
} Node;

typedef struct {
    int elems;
    pNode primer;
    pNode ultim;
    pNode pdi;
} llista_encadenada;

/*He probado tanto de esta manera y tambien solo con la estructura nodo pero poniendole de nombre llista_encadenada y creando variables globales de tipo nodo head, tail y pdi*/
int Crear(llista_encadenada* ll);
int Destruir(llista_encadenada* ll);
int Principi(llista_encadenada* ll);
int Final(llista_encadenada* ll);
int Avancar(llista_encadenada* ll);
int Retrocedir(llista_encadenada* ll);
int Es_Final(llista_encadenada ll, bool* esfinal);
int Actual(llista_encadenada ll, int* elem);
int Inserir(llista_encadenada* ll, int elem);
int Esborrar(llista_encadenada* ll);
int Longitud(llista_encadenada ll, int* lon);
int Buscar(llista_encadenada ll, int elem, bool* trobat);
int Cost_Buscar(llista_encadenada ll, int elem, int* cost);
void imprimir(llista_encadenada ll);
void imprimir(llista_encadenada ll);
Node* CrearNodo();
