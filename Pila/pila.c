#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define MAX_ELEM 10


Pila Crear(int size)
{
	Pila* p = (Pila*)malloc(sizeof(Pila));
	p->data = malloc(sizeof(int) * size);
	p->maxElems = size;
	p->numElems = 0;
	return *p;
}
int Cim(Pila p)
{
	if (p.data == NULL)
	{
		printf("La pila no existe");
		exit(1);
	}
	if (p.numElems >= 0)
	{
		if (!EsBuida(p))
		{
			return p.data[p.numElems - 1];
		}
		else
		{
			printf("La pila esta vacia");
			exit(1);
		}
	}
	else
	{
		printf("La pila no existe");
	}

}
void Apilar(Pila* ap, int elem)
{
	if (ap->data == NULL)
	{
		printf("La pila no existe");
		exit(1);
	}
	if (ap->numElems >= 0)
	{
		if (!EsPlena(*ap))
		{
			ap->data[ap->numElems] = elem;
			ap->numElems = ap->numElems + 1;
		}
		else
		{
			printf("La pila esta llena no se pueden agregar elementos");
		}
	}
	else
	{
		printf("La pila no existe");
	}

}
void Desapilar(Pila* ap)
{
	if (ap == NULL)
	{
		printf("La pila no existe");
		exit(1);
	}
	if (ap->numElems >= 0)
	{
		if (EsBuida(*ap))
		{
			printf("La pila esta vacia");
		}
		else
		{
			ap->data[ap->numElems - 1] = NULL;
			ap->numElems = ap->numElems - 1;
		}
	}

}
bool EsBuida(Pila p)
{
	if (p.data == NULL)
	{
		printf("La pila no existe");
		exit(1);
	}
	if (p.numElems > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool EsPlena(Pila p)
{
	if (p.data == NULL)
	{
		printf("La pila no existe");
		exit(1);
	}
	if (p.numElems == p.maxElems)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Destruir(Pila* ap)
{
	ap->maxElems = 0;
	ap->numElems = 0;
	ap->data = NULL;
	free(ap);
}
void duplicar(Pila* ap)
{
	int temp = Cim(*ap);
	Desapilar(ap);
	Apilar(ap, temp);
	Apilar(ap, temp);
}
void repetirNveces(Pila* ap,int rep)
{
	int temp = Cim(*ap);
	if (ap->numElems + rep <= ap->maxElems)
	{
		Desapilar(ap);
		for (int i = 0; i < rep; i++)
		{
			Apilar(ap, temp);
		}
		Apilar(ap, temp);
	}
}
void permutacionNelems(Pila* ap, int elems)
{
	int vector[MAX_ELEM];
	int i;
	for (i = 0; i < elems; i++)
	{
		vector[i] = Cim(*ap);
		Desapilar(ap);
	}
	for (i = 0; i < elems; i++)
	{
		Apilar(ap, vector[i]);
	}

}