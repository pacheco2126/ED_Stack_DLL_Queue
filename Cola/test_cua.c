#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cua.h"
#include "test_cua.h"

void pruebaCrear(int* oks, int* errors)
{
	Cua c;
	int resultado = Crear(&c, 10);

	if (resultado == 0 && c.maxElems == 10)
	{
		(*oks)++;
	}
	else 
	{
		(*errors)++;
		printf("Error creando cola\n");
	}

}
void pruebaEncuar(int* oks, int* errors)
{
	Cua c;
	int resultado;
	Crear(&c, 10);
	resultado = Encuar(&c, 20);
	if (c.indexIn == 1 && c.data[c.indexOut] == 20 && resultado == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error agregando a la cola\n");
	}
}
void pruebaDesencuar(int* oks, int* errors)
{
	Cua c;
	int resultado;
	Crear(&c, 10);
	Encuar(&c, 20);
	Encuar(&c, 30);
	Encuar(&c, 40);
	resultado = Desencuar(&c);
	if (c.indexOut == 1 && resultado == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error quitando de la cola\n");
	}
}
void pruebaCap(int* oks, int* errors)
{
	Cua c;
	int resultado;
	int elem;
	Crear(&c, 10);
	Encuar(&c, 20);
	Encuar(&c, 30);
	Encuar(&c, 40);
	resultado = Cap(c, &elem);
	if (elem == 20 && resultado == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error cogiendo el primer valor de la cola\n");
	}
}
void pruebaBuida(int* oks, int* errors)
{
	Cua c;
	int resultado;
	bool boleano;
	Crear(&c, 10);
	resultado = EsBuida(c, &boleano);
	if (boleano == true && resultado == 4)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error probando buida\n");
	}
}
void pruebaPlena(int* oks, int* errors)
{
	Cua c;
	int resultado;
	bool boleano;
	Crear(&c, 10);
	resultado = EsPlena(c, &boleano);
	if (boleano == false && resultado == 4)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error probando plena\n");
	}
}
void pruebaDestruir(int* oks, int* errors)
{
	/**Terminar de comprobar porque no destruye bien la pila*/
	Cua c;
	Crear(&c, 10);
	int resultado = Destruir(&c);
	if (resultado == 0)
	{
		(*oks)++;
	}
	else
	{
		(*errors)++;
		printf("Error destruir\n");
	}

}
void test(int* oks, int* errors)
{
	oks = 0;
	errors = 0;
	printf("\n--------------------------------EMPEZANDO TEST COLA-------------------------------------\n");
	printf("\nNumero de oks al comenzar: %i  numero de errores al comenzar: %i\n", oks, errors);
	pruebaCrear(oks, errors);
	pruebaDesencuar(oks, errors);
	pruebaCap(oks, errors);
	pruebaDestruir(oks, errors);
	pruebaEncuar(oks, errors);
	pruebaPlena(oks, errors);
	pruebaBuida(oks, errors);
	printf("\nNumero de oks al acabar: %i  numero de errores al acabar: %i\n", oks, errors);
	printf("\n--------------------------------ACABANDO TEST COLA----------------------------------------------\n");
}