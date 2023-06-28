#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cua.h"

int Crear(Cua* ac, int size)
{
	ac->data = (int*)malloc(sizeof(int)*size);
	ac->maxElems = size;
	ac->indexIn = 0;
	ac->indexOut = 0;
	for (int i = 0; i < ac->maxElems; i++)
	{
		ac->data[i] = NULL;
	}
	if (ac->data != NULL && ac->indexIn == 0 && ac->indexOut == 0 && ac->maxElems == size)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR_CREAR;
	}
}
int Encuar(Cua* ac, int elem)
{
	bool plena;
	if (ac->data == NULL)
	{
		return CUA_NO_CREADA;
	}
	EsPlena(*ac, &plena);
	if (!plena)
	{
		ac->indexIn = (ac->indexIn) % ac->maxElems;
		ac->data[ac->indexIn] = elem;
		ac->indexIn++;
		return SUCCESS;
	}
	else
	{
		printf("Hola");
		return CUA_PLENA;
	}
	
}
int Desencuar(Cua* ac)
{
	bool vacia;
	if (ac->data == NULL)
	{
		return CUA_NO_CREADA;
	}
	EsBuida(*ac, &vacia);
	if (!vacia)
	{
		ac->data[ac->indexOut] == NULL;
		ac->indexOut++;
		if (ac->indexOut >= ac->maxElems)
		{
			ac->indexOut == 0;
		}
		return SUCCESS;
	}
	else
	{
		return CUA_BUIDA;
	}
}
int Cap(Cua ac, int* elem)
{
	bool vacia;
	if (ac.data == NULL)
	{
		return CUA_NO_CREADA;
	}
	EsBuida(ac, &vacia);
	if (!vacia)
	{
		*elem = ac.data[ac.indexOut];
		return SUCCESS;
	}
	else
	{
		return CUA_BUIDA;
	}
}
int EsBuida(Cua c, bool* b)
{
	if (c.data == NULL)
	{
		return CUA_NO_CREADA;
	}
	if (c.indexIn == c.indexOut)
	{
		if (c.indexIn - 1 == -1)
		{
			if (c.data[(c.indexIn + c.maxElems - 1)] == NULL)
			{
				*b = true;
				return CUA_BUIDA;
			}
			else
			{
				*b = false;
				return CUA_PLENA;
			}
		}
		else if (c.data[(c.indexIn - 1)] == NULL)
		{
			*b = true;
			return CUA_BUIDA;
		}
		else
		{
			*b = false;
			return CUA_PLENA;
		}
	}
	else
	{
		*b = false;
		return CUA_PLENA;
	}
}
int EsPlena(Cua c, bool* b)
{
	if (c.data == NULL)
	{
		return CUA_NO_CREADA;
	}
	if (c.indexOut == c.indexIn)
	{
		if (c.indexIn - 1 == -1)
		{
			if (c.data[(c.indexIn+c.maxElems-1)] != NULL)
			{
				*b = true;
				return CUA_PLENA;
			}
			else
			{
				*b = false;
				return CUA_BUIDA;
			}
		}
		else if (c.data[(c.indexIn - 1)] != NULL)
		{
			*b = true;
			return CUA_PLENA;
		}
		else
		{
			*b = false;
			return CUA_BUIDA;
		}
	}
	else
	{
		*b = false;
		return CUA_BUIDA;
	}
}
int Destruir(Cua* ac)
{
	ac->data = NULL;
	ac->indexIn = 0;
	ac->indexOut = 0;
	ac->maxElems = 0;
	free(ac->data);
	if (ac->data != NULL)
	{
		return ERROR_DESTRUIR;
	}
	else
	{
		return SUCCESS;
	}
}