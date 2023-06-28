#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEVEL 15
#define SUCCESS 0
#define ERROR_NO_EXISTEIX 1
#define ES_FINAL 2
#define ERROR_DESTRUCCION 3

typedef struct node* pNode;

typedef struct node {
    int data;
    pNode prev;
    pNode Next;
    pNode up;
    pNode down;
} Node;

typedef struct {
    int level;
    pNode header;
    pNode tail;
    
} skip_list;

int Crear(skip_list* sl);
int Destruir(skip_list* sl);
int Inserir(skip_list* sl, int elem);
int Esborrar(skip_list* sl, int elem);
int Longitud(skip_list sl, int* lon);
int Buscar(skip_list sl, int elem, bool* trobat);
int Cost_Buscar(skip_list sl, int elem, int* cost);
Node* buscarElemIgual(int elem, skip_list sl);
Node* buscarKey(int elem, skip_list sl);
int random_level();
Node* CrearNodo();
