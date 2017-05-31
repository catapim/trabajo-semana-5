#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int numero; /* el numero */
} nodo;

typedef struct {
	nodo* desde;
	nodo* hacia;
} enlace;


int main()
{
	printf("Hello World");
	nodo nodos[6];
	nodos[0].numero = 1;
	nodos[1].numero = 2;
	nodos[2].numero = 3;
	nodos[3].numero = 4;
	nodos[4].numero = 5;
	nodos[5].numero = 6;

	enlace enlaces[9];
	enlaces[0].desde = &nodos[0];
	enlaces[0].hacia = &nodos[1];
	enlaces[1].desde = &nodos[0];
	enlaces[1].hacia = &nodos[2];
	enlaces[2].desde = &nodos[1];
	enlaces[2].hacia = &nodos[2];
	enlaces[3].desde = &nodos[1];
	enlaces[3].hacia = &nodos[3];
	enlaces[4].desde = &nodos[2];
	enlaces[4].hacia = &nodos[4];
	enlaces[5].desde = &nodos[3];
	enlaces[5].hacia = &nodos[2];
	enlaces[6].desde = &nodos[4];
	enlaces[6].hacia = &nodos[3];
	enlaces[7].desde = &nodos[3];
	enlaces[7].hacia = &nodos[5];
	enlaces[8].desde = &nodos[4];
	enlaces[8].hacia = &nodos[5];

	printf("");



};