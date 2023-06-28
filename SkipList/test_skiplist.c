#include "test_skiplist.h"
#include"skiplist.h"
int Crear(skip_list* sl);
int Destruir(skip_list* sl);
int Inserir(skip_list* sl, int elem);
int Esborrar(skip_list* sl, int elem);
int Longitud(skip_list sl, int* lon);
int Buscar(skip_list sl, int elem, bool* trobat);
int Cost_Buscar(skip_list sl, int elem, int* cost);
void pruebaCrear(int* oks, int* errors)
{
	skip_list lista;
	int result;
	result = Crear(&lista);
	if (lista.level == 0 && lista.header && lista.tail && result == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error prueba Crear\n");
	}
}
void pruebaDestruir(int* oks, int* errors)
{
	skip_list lista;
	Crear(&lista);
	int result;
	result = Destruir(&lista);
	if (result == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error prueba Destruir\n");
	}
}
void pruebaInserir(int* oks, int* errors)
{
	skip_list lista;
	Crear(&lista);
	int result;
	int size;
	result = Inserir(&lista, 10);
	Inserir(&lista, 5);
	if (result == 0)
	{
		result = Longitud(lista, &size);
		if (result == 0 && size == 2)
		{
			(*oks)++;
		}
		else
		{
			(*errors)++;
			printf("Error probando inserir\n");
		}
	}
	else
	{
		(*errors)++;
		printf("Error probando inserir\n");
	}

}
void pruebaEsborrar(int* oks, int* errors)
{
	skip_list lista;
	Crear(&lista);
	int result;
	int size;
	result = Inserir(&lista, 10);
	result = Inserir(&lista, 5);
	if (result == 0)
	{
		result = Esborrar(&lista, 10);
		result = Longitud(lista, &size);
		if (result == 0 && size == 1)
		{
			(*oks)++;
		}
		else
		{
			(*errors)++;
			printf("Error probando eliminar\n");
		}
	}
	else
	{
		(*errors)++;
		printf("Error probando eliminar\n");
	}
}
void pruebaLongitud(int* oks, int* errors)
{
	skip_list lista;
	Crear(&lista);
	int result;
	int size;
	result = Inserir(&lista, 10);
	result = Inserir(&lista, 20);
	result = Longitud(lista, &size);
	if (result == 0 && size == 2)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error prueba Longitud\n");
	}
}
void pruebaBuscar(int* oks, int* errors)
{
	skip_list lista;
	Crear(&lista);
	int result;
	bool encontrado;
	result = Inserir(&lista, 10);
	result = Buscar(lista, 10, &encontrado);
	if (encontrado && result == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error prueba buscar\n");
	}
}
void pruebaCost_buscar(int* oks, int* errors)
{
	skip_list lista;
	Crear(&lista);
	int result;
	int cost = 0;
	result = Inserir(&lista, 10);
	result = Inserir(&lista, 4000);
	result = Cost_Buscar(lista, 10, &cost);
	if (cost > 0 && result == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error prueba cost_buscar\n");
	}
}
void test(int *oks, int *errors)
{
	printf("\n-----------------------------INICIANDO PRUEBAS SKIP_LIST-----------------------------------\n");
	pruebaCrear(oks, errors);
	pruebaDestruir(oks, errors);
	pruebaLongitud(oks, errors);
	pruebaEsborrar(oks, errors);
	pruebaCost_buscar(oks, errors);
	pruebaInserir(oks, errors);
}