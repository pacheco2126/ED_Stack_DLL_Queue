#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#define MAX_ELEMS 100
void main()
{
	int a, b;
	int resultado = 0;
	int thrash;
	int i = 0;
	int j = 0;
	Pila p = Crear(10);
	FILE* file = fopen("input.txt", "r");
	char vector[MAX_ELEMS][MAX_ELEMS] = { NULL };
	if (file == NULL)
	{
		printf("No se ha podido abrir el archivo");
	}
	else
	{
		while (!feof(file))
		{
			thrash = fscanf(file, "%s", vector[i]);
			i++;
		}
	}
	while (j < i)
	{
		char* ptr = strtok(vector[j], ",");
		while (ptr != NULL)
		{
			char* chs = "chs";
			if ((isdigit(*ptr) > 0) || (isdigit(*(ptr + 1)) > 0))
			{
				int value = atoi(ptr);
				Apilar(&p, value);
			}
			else
			{
				switch (*ptr)
				{
				case '/':
					if (p.numElems >= 2)
					{
						a = Cim(p);
						Desapilar(&p);
						b = Cim(p);
						Desapilar(&p);
						b = b / a;
						Apilar(&p, b);
					}
					break;
				case '+':
					if (p.numElems >= 2)
					{
						a = Cim(p);
						Desapilar(&p);
						b = Cim(p);
						Desapilar(&p);
						b = b + a;
						Apilar(&p, b);
					}
					break;
				case '-':
					if (p.numElems >= 2)
					{
						a = Cim(p);
						Desapilar(&p);
						b = Cim(p);
						Desapilar(&p);
						b = b - a;
						Apilar(&p, b);
					}
					break;
				case '*':
					if (p.numElems >= 2)
					{
						a = Cim(p);
						Desapilar(&p);
						b = Cim(p);
						Desapilar(&p);
						b = b * a;
						Apilar(&p, b);
					}
					break;
				case '!':
					if (!EsBuida(p))
					{
						a = Cim(p);
						Desapilar(&p);
						resultado = 1;
						if (a == 0)
						{
							resultado = 0;
						}
						for (int i = 1; i <= a; i++)
						{
							resultado = resultado * i;
						}
						Apilar(&p, resultado);
					}
					break;
				case '^':
					if (p.numElems >= 2)
					{
						a = Cim(p);
						Desapilar(&p);
						b = Cim(p);
						Desapilar(&p);
						resultado = b;
						if (a == 0)
						{
							resultado = 1;
						}
						for (int i = 1; i < a; i++)
						{
							resultado = resultado * b;
						}
						Apilar(&p, resultado);
					}
					break;
				case '|':
					if (!EsBuida(p))
					{
						a = Cim(p);
						Desapilar(&p);
						if (a < 0)
						{
							a = a * -1;
						}
						Apilar(&p, a);
					}
					break;
				default:
					if (strcmp(ptr, chs) == 0)
					{
						if (!EsBuida(p))
						{
							a = Cim(p);
							Desapilar(&p);
							a = a * -1;
							Apilar(&p, a);
						}
					}
					break;
				}
			}
			ptr = strtok(NULL, ",");
		}
		printf("%d\n", Cim(p));
		j++;
	}
}