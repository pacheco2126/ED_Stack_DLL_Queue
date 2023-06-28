#include <stdio.h>
#include <stdlib.h>
#include "llista_encadenada.h"

Node* CrearNodo()
{
	Node* nuevoNodo;
	nuevoNodo = malloc(sizeof(Node));
	nuevoNodo->Next = NULL;
	nuevoNodo->prev = NULL;

	return nuevoNodo;
}
int Crear(llista_encadenada* ll)
{
	ll->primer = NULL;
	ll->ultim = NULL;
	ll->pdi = NULL;
	ll->elems = 0;
	return SUCCESS;
}

int Destruir(llista_encadenada* ll)
{
	ll->primer = NULL;
	ll->elems = NULL;
	ll->pdi = NULL;
	ll->ultim = NULL;
	ll = NULL;
	free(ll);
	return SUCCESS;

}
int Principi(llista_encadenada* ll)
{
	if (ll)
	{
		if (ll->primer)
		{
			ll->pdi = ll->primer->Next;
			return SUCCESS;

		}
		else
		{
			return ERROR_PDI_NEXT_OR_PREV;
		}
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Final(llista_encadenada* ll)
{
	if (ll)
	{
		if (ll->ultim)
		{
			ll->pdi = ll->ultim;
			return SUCCESS;

		}
		else
		{
			return ERROR_PDI_NEXT_OR_PREV;
		}
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Avancar(llista_encadenada* ll)
{
	if (ll)
	{
		if (ll->pdi->Next)
		{
			ll->pdi = ll->pdi->Next;
			return SUCCESS;

		}
		else
		{
			return ERROR_PDI_NEXT_OR_PREV;
		}
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Retrocedir(llista_encadenada* ll)
{
	if (ll)
	{
		if (ll->pdi->prev)
		{
			ll->pdi = ll->pdi->prev;
			return SUCCESS;

		}
		else
		{
			return ERROR_PDI_NEXT_OR_PREV;
		}
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Es_Final(llista_encadenada ll, bool* esfinal)
{
	if (&ll)
	{
		if (ll.pdi == ll.ultim)
		{
			*esfinal = true;
			return ES_FINAL;

		}
		else
		{
			return ERROR_PDI_NEXT_OR_PREV;
		}
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Actual(llista_encadenada ll, int* elem)
{
	*elem = ll.pdi->data;
	return SUCCESS;

}
int Inserir(llista_encadenada* ll, int elem)
{
	if (ll)
	{
		if (!ll->ultim)
		{
			Node* nuevoNodo = CrearNodo();
			Node* elementoFantasma = CrearNodo();
			Node* elementoFantasmaPri = CrearNodo();
			elementoFantasmaPri->Next = nuevoNodo;
			elementoFantasmaPri->data = NULL;
			nuevoNodo->data = elem;
			ll->primer = elementoFantasmaPri;
			elementoFantasma->data = NULL;
			elementoFantasma->prev = nuevoNodo;
			ll->ultim = elementoFantasma;
			ll->pdi = elementoFantasma;
			nuevoNodo->prev = NULL;
			nuevoNodo->Next = ll->pdi;
		}
		else
		{
			Node* nuevoNodo = CrearNodo();
			nuevoNodo->data = elem;
			nuevoNodo->Next = ll->pdi;
			nuevoNodo->prev = ll->pdi->prev;
			ll->pdi->prev->Next = nuevoNodo;
			ll->pdi->prev = nuevoNodo;
		}
		ll->elems++;
		return SUCCESS;

	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Esborrar(llista_encadenada* ll)
{
	if (ll)
	{
		if ((ll->pdi) && (ll->ultim != ll->pdi) && (ll->pdi != ll->primer))
		{
			ll->pdi->prev->Next = ll->pdi->Next;
			ll->primer == NULL;
			ll->pdi->Next->prev = ll->pdi->prev;
			ll->pdi = ll->pdi->Next;
			ll->elems--;
			if (ll->elems == 0)
			{
				ll->ultim = NULL;
				ll->pdi = NULL;
				ll->primer = NULL;
			}
			return SUCCESS;
		}
		else
		{
			return ERROR_PDI_NEXT_OR_PREV;
		}
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Longitud(llista_encadenada ll, int* lon)
{
	if (&ll)
	{
		if (ll.elems >= 0) 
		{
			*lon = ll.elems;
			return SUCCESS;
		}
	}
}
int Buscar(llista_encadenada ll, int elem, bool* trobat)
{
	if (ll)
	{
		*trobat = false;
		Node* ptr = ll.primer->Next;
		while (ptr != ll.ultim && ptr->data != elem)
		{
			ptr = ptr->Next;
		}
		if (ptr->data == elem)
		{
			*trobat = true;
		}
		return SUCCESS;
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}

}
int Cost_Buscar(llista_encadenada ll, int elem, int* cost)
{
	if (ll)
	{
		*cost = 0;
		Node* ptr = ll.primer->Next;
		while (ptr != ll.ultim && ptr->data != elem)
		{
			ptr = ptr->Next;
			(*cost)++;
		}
		return SUCCESS;
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}