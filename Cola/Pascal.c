#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cua.h"
#include "test_cua.h"
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMS 100
void TrianguloPascal(int valor)
{
	Cua Colas[MAX_ELEMS];
	for (int i = 1; i < valor; i++)
	{
		Crear(&Colas[i-1], i);
	}
	int Valor;
	int MaxElemsCola;
	int Cola = 0;
	int Indice = -1;
	do{
		MaxElemsCola = Colas[Cola].maxElems;
		for (int i = 0; i < MaxElemsCola; i++)
		{
			if (i + 1 != MaxElemsCola && i != 0)
			{
				Encuar(&Colas[Cola], Colas[Indice].data[i] + Colas[Indice].data[i - 1]);

			}
			if (i == 0)
			{
				Encuar(&Colas[Cola], 1);
			}
			if (i + 1 == MaxElemsCola)
			{
				Encuar(&Colas[Cola], 1);
			}
		}
		for (int i = 0; i < MaxElemsCola; i++)
		{
			Cap(Colas[Cola], &Valor);
			printf("%i ", Valor);
			Desencuar(&Colas[Cola]);
		}
		printf("\n");
		Cola++;
		Indice++;
	} while (Cola < valor - 1);
}


int main()
{
	int valor;
	int iteracciones;
	printf("Buenas, a continuación vamos a realizar el triangulo de pascal, cuantos niveles desea que tenga?\n");
	scanf("%i", &valor);
	TrianguloPascal(valor);
}