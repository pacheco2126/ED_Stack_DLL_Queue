#include "skiplist.h"
int random_level()
{
	int level = 1;
	while (rand() < RAND_MAX / 2 && level <= MAX_LEVEL)
		level++;

	return level;
}
Node* CrearNodo()
{
	Node* nuevoNodo;
	nuevoNodo = malloc(sizeof(Node));
	nuevoNodo->Next = NULL;
	nuevoNodo->prev = NULL;
	nuevoNodo->up = NULL;
	nuevoNodo->down = NULL;

	return nuevoNodo;
}
int Crear(skip_list* sl)
{
	sl->level = 0;
	Node* nodoLeft = CrearNodo();
	Node* nodoRight = CrearNodo();
	nodoLeft->data = -INT_MAX;
	nodoRight->data = INT_MAX;
	nodoLeft->Next = nodoRight;
	nodoRight->prev = nodoLeft;
	sl->header = nodoLeft;
	sl->tail = nodoRight;
	return SUCCESS;
}
int Destruir(skip_list* sl)
{
	if (sl->header)
	{
		sl->header = NULL;
		sl->level = NULL;
		sl->tail = NULL;
		sl = NULL;
		free(sl);
		if (!sl)
		{
			return SUCCESS;
		}
		else
		{
			return ERROR_DESTRUCCION;
		}
	}
}
Node* buscarKey(int elem,skip_list sl)
{
	if (sl.header)
	{
		Node* ptr = sl.header;
		int level = sl.level;
		int cont = 0;
		while (true)
		{
			if (elem > ptr->Next->data)
			{
				ptr = ptr->Next;
			}
			else if (level > 0)
			{
				if (ptr->down)
				{
					ptr = ptr->down;
					level--;
				}
			}
			else if (ptr->Next->data >= elem && level == 0)
			{
				return ptr;
			}
		}
	}
}
Node* buscarElemIgual(int elem, skip_list sl)
{
	if (sl.header)
	{
		Node* ptr = sl.header;
		int level = sl.level;
		while (true)
		{
			if (elem >= ptr->Next->data)
			{
				ptr = ptr->Next;
			}
			else if (level > 0)
			{
				if (ptr->down)
				{
					ptr = ptr->down;
					level--;
				}
			}
			else if (elem == ptr->data && level == 0)
			{
				return ptr;
			}
			else if (ptr->Next->data > elem&& level == 0 && ptr->data != elem)
			{
				return NULL;
			}
		}
	}
}
int Inserir(skip_list* sl, int elem)
{
	if (sl->header)
	{
		Node* ptr = buscarKey(elem, *sl);
		Node* AuxNode = CrearNodo();
		int levelRand = random_level();
		int level_or = sl->level;
		for (int i = 0; i <= levelRand; i++)
		{
			Node* newNode = CrearNodo();
			newNode->data = elem;
			if (i > sl->level)
			{
				Node* nodeLeft = CrearNodo();
				Node* noderight = CrearNodo();
				nodeLeft->data = -INT_MAX;
				noderight->data = INT_MAX;
				newNode->prev = nodeLeft;
				newNode->Next = noderight;
				nodeLeft->Next = newNode;
				nodeLeft->down = sl->header;
				noderight->down = sl->tail;
				sl->header->up = nodeLeft;
				sl->tail->up = noderight;
				sl->header = nodeLeft;
				sl->tail = noderight;
				noderight->prev = newNode;
				sl->level++;
			}
			else
			{
				newNode->Next = ptr->Next;
				newNode->prev = ptr;
				ptr->Next->prev = newNode;
				ptr->Next = newNode;
				if (ptr->up)
				{
					ptr = ptr->up;
				}
				else
				{
					if (i + 1 <= level_or)
					{
						while (!ptr->up)
						{
							if (ptr->prev)
							{
								ptr = ptr->prev;
							}
						}
						if (ptr->up)
						{
							ptr = ptr->up;
						}
					}
				}
			}
			if (i > 0)
			{
				newNode->down = AuxNode;
				AuxNode->up = newNode;
			}
			AuxNode = newNode;

		}
		return SUCCESS;
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Esborrar(skip_list* sl, int elem)
{
	if (sl->header)
	{
		Node* eliminar = buscarElemIgual(elem, *sl);
		while (eliminar)
		{
			eliminar->prev->Next = eliminar->Next;
			eliminar->Next->prev = eliminar->prev;
			while (eliminar->up)
			{
				eliminar = eliminar->up;
				eliminar->prev->Next = eliminar->Next;
				eliminar->Next->prev = eliminar->prev;
			}
			eliminar = buscarElemIgual(elem, *sl);
		}
		return SUCCESS;
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Longitud(skip_list sl, int* lon)
{
	if (sl.header)
	{
		Node* ptr = sl.header;
		int cont = 0;
		while (ptr->down)
		{
			ptr = ptr->down;
		}
		while (ptr->Next)
		{
			ptr = ptr->Next;
			cont++;
		}
		cont--;
		*lon = cont;
		return SUCCESS;
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}
}
int Buscar(skip_list sl, int elem, bool* trobat)
{
	if (sl.header)
	{
		Node* ptr = sl.header;
		while (ptr->data != elem)
		{
			if (elem > ptr->data)
			{
				ptr = ptr->Next;
			}
			else
			{
				if (ptr->down)
				{
					ptr = ptr->down;
				}
			}
			if (ptr->data == elem)
			{
				*trobat = true;
				return 0;
			}
		}
		return SUCCESS;
	}
	else
	{
		return ERROR_NO_EXISTEIX;
	}

}
int Cost_Buscar(skip_list sl, int elem, int* cost)
{
	if (sl.header)
	{
		Node* ptr = sl.header;
		int level = sl.level;
		int cont = 0;
		while ((ptr->data != elem))
		{
			if (elem >= ptr->Next->data)
			{
				ptr = ptr->Next;
			}
			else
			{
				if (ptr->down)
				{
					ptr = ptr->down;
					level--;
				}
			}
			if (ptr->data == elem)
			{
				return SUCCESS;
			}
			else if (ptr->Next->data > elem&& level == 0)
			{
				return SUCCESS;
			}
			(*cost)++;
		}
		return SUCCESS;
	}
}