#include "llista_encadenada.h"
#include "random.h"
#include <math.h>
#define _CRT_SECURE_NO_DEPRECATE
#define MAX_SEARCH 1000
int crearlista(int elems,float* desvEst)
{
	int randomNumber;
	int cost = 0;
	float valor = 0;
	long elem = 2 * elems;
	float valores[MAX_SEARCH];
	float media = 0;
	llista_encadenada llista;
	Crear(&llista);
	for (int i = 0; i < elems; i++)
	{
		randomNumber = ignuin(1, elem);
		Inserir(&llista, randomNumber);
	}
	for (int i = 0; i < MAX_SEARCH; i++)
	{
		randomNumber = ignuin(1, elem);
		Cost_Buscar(llista, randomNumber, &cost);
		valores[i] = cost;
		media = media + cost;
	}
	media = (media / MAX_SEARCH);
	for (int i = 0; i < MAX_SEARCH; i++)
	{
		valor = valor + (((valores[i] - media)*(valores[i]-media))/MAX_SEARCH);
	}
	valor = sqrt(valor);
	*desvEst = valor;
	return media;
}
void main()
{
	long seed1, seed2;
	phrtsd("Hola", &seed1, &seed2);
	setall(seed1, seed2);
	FILE* file;
	float desvEst = 0;
	file = fopen("datos.csv", "w+");
	float cost[50];
	fprintf(file, "mida,cost,desv.Est\n");
	for (int i = 0; i < 50; i++)
	{
		cost[i] = crearlista((i+1)*1000,&desvEst);
		printf("%f\n", desvEst);
		fprintf(file, "%i,%.2f,%.2f \n", (i+1)*1000,cost[i],desvEst);
	}
	
}