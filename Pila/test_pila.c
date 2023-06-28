#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "test_pila.h"

void pruebaCim(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	Apilar(&p, 10);
	if (Cim(p) == 10)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaCim 1");
	}
	Apilar(&p, 3);
	if (Cim(p) == 3)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaCim 2");
	}
}

void pruebaCrear(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	if (p.maxElems == 10  && p.numElems == 0)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaCrear");
	}
}
void pruebaApilar(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	Apilar(&p, 10);
	if (Cim(p) == 10 && p.numElems == 1)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaApilar 1");
	}
	Apilar(&p, 3);
	if (Cim(p) == 3 && p.numElems == 2)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaApilar 2");
	}
}
void pruebaDesapilar(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	Apilar(&p, 10);
	Apilar(&p, 3);
	Desapilar(&p);
	if (Cim(p) == 10 && p.numElems == 1)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaDesapilar");
	}
}
void pruebaEsbuida(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	if (EsBuida(p))
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaEsbuida 1");
	}
	Apilar(&p, 3);
	if (!EsBuida(p))
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaEsbuida 2");
	}
}
void pruebaEsplena(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	if (!EsPlena(p))
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaEsPlena");
	}

}
void pruebaDuplicar(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	Apilar(&p, 10);
	Apilar(&p, 3);
	duplicar(&p);
	if (p.numElems == 3 && Cim(p) == 3)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaDuplicar");
	}

}
void pruebaPermutacion(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	Apilar(&p, 10);
	Apilar(&p, 3);
	permutacionNelems(&p, 2);
	if (p.numElems == 2 && Cim(p) == 10)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaDuplicar");
	}
}
void pruebaMultip(int* numOks, int* numErrors)
{
	Pila p = Crear(10);
	Apilar(&p, 10);
	Apilar(&p, 3);
	repetirNveces(&p,3);
	if (p.numElems == 5 && Cim(p) == 3)
	{
		(*numOks)++;
	}
	else
	{
		(*numErrors)++;
		printf("Problema pruebaDuplicar");
	}
}
void test(int* numOks , int* numErrors)
{
	numOks = 0;
	numErrors = 0;
	printf("------------------------Comenzando test de pruebas------------------------\n");
	printf("Numero de pruebas asolidas correctamente al momento de empezar el test: %i\n", numOks);
	printf("Numero de pruebas asolidas incorrectamente al momento de empezar el test: %i\n", numErrors);
	pruebaApilar(numOks, numErrors);
	pruebaCim(numOks, numErrors);
	pruebaCrear(numOks, numErrors);
	pruebaEsbuida(numOks, numErrors);
	pruebaEsplena(numOks, numErrors);
	pruebaDuplicar(numOks, numErrors);
	pruebaMultip(numOks, numErrors);
	pruebaPermutacion(numOks, numErrors);
	printf("Numero de pruebas asolidas correctamente al momento de acabar el test: %i\n", numOks);
	printf("Numero de pruebas asolidas incorrectamente al momento de acabar el test: %i\n", numErrors);
}