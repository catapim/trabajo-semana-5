#include<stdio.h>
#include<stdlib.h>
/************************************************************/
typedef struct x {
	int num;
	struct x *prox;
}
x;
typedef struct centinela {
	struct pila *inicio;
	struct pila *fin;
}
centinela;
typedef struct pila {
	int num;
	struct pila *prox;
}
pila;
/************************************************************/
char error[] = {
	"Opcion Invalida!\n"
}
;
/************************************************************/
void menu(x *grafo, int tam);
x *inserta_arista(x *grafo, int tam);
void imprime(x *grafo, int tam);
void busqueda_en_profundidad(x *grafo, int tam, int inicio);
pila *desapila(pila *p);
pila *apila(pila *p, int num);
centinela *inserta_fila(centinela *filas, int num);
centinela *desenfila(centinela *filas);
void busqueda_por_anchura(x *grafo, int tam, int inicio);
/************************************************************/
int main() {
	x *grafo = NULL;
	int tam;

	printf("\n\tIngresa tama%co del Vector: ", 164);
	scanf("%d", &tam);
	grafo = (x *)malloc(tam * sizeof(x));
	if (!grafo) {
		puts("ERROR\n");
		system("pause");
		exit(0);
	}
	system("cls");
	menu(grafo, tam);
}
/************************************************************/
void menu(x *grafo, int tam) {
	int op, i;
	for (i = 0; i<tam; i++) {
		grafo[i].num = i;
		grafo[i].prox = NULL;
	}
	system("cls");
	do {
		printf("\n\t 1 - Insertar Aristas\n");
		printf("\t 2 - Imprimir\n");
		printf("\t 3 - Busqueda en profundidad\n");
		printf("\t 4 - Busqueda en anchura\n");
		printf("\t 5 - Salir\n\n");
		printf("\tOpciones: ");
		scanf("%d", &op);
		switch (op) {
		case 1: grafo = inserta_arista(grafo, tam);
			break;
		case 2: imprime(grafo, tam);
			break;
		case 3: busqueda_en_profundidad(grafo, tam, grafo[0].num);
			break;
		case 4: busqueda_por_anchura(grafo, tam, grafo[0].num);
			break;
		case 5:exit(0);
			break;
		default: printf(error);
			break;
		}
		system("pause");
		system("cls");
	} while (op != 5);
}
/************************************************************/
x *inserta_arista(x *grafo, int tam) {
	int n1, n2, i;
	x *nuevo, *out;
	x *aux;
	printf("Inserte la arista\n");
	printf("1 Punto: ");
	scanf("%d", &n1);
	printf("2 Punto: ");
	scanf("%d", &n2);
	if (n1 == n2) {
		nuevo = (x *)malloc(sizeof(x));
		nuevo->num = n2;
		nuevo->prox = NULL;
		nuevo->prox = grafo[n1].prox;
		grafo[n1].prox = nuevo;
	}
	else {
		nuevo = (x *)malloc(sizeof(x));
		nuevo->prox = NULL;
		nuevo->num = n2;
		nuevo->prox = grafo[n1].prox;
		grafo[n1].prox = nuevo;
		out = (x *)malloc(sizeof(x));
		out->prox = NULL;
		out->num = n1;
		out->prox = grafo[n2].prox;
		grafo[n2].prox = out;
	}
	printf("\n\tOK\n\n");
	return grafo;
}
/************************************************************/
void imprime(x *grafo, int tam) {
	x *aux;
	int i;
	for (i = 0; i<tam; i++) {
		printf("Lista de Numeros: %d :", grafo[i].num);
		if (grafo[i].prox == NULL)
			continue;
		aux = grafo[i].prox;
		while (aux != NULL) {
			printf(" ->%d", aux->num);
			aux = aux->prox;
		}
		puts("\n\n");
	}
}
/************************************************************/
pila *apila(pila *p, int num) {
	pila *aux = (pila *)malloc(sizeof(pila));
	aux->num = num;
	if (p != NULL)
		aux->prox = p; else
		aux->prox = NULL;
	return aux;
}
/************************************************************/
pila *desapila(pila *p) {
	pila *aux = p;
	p = p->prox;
	free(aux);
	return p;
}
/************************************************************/
void busqueda_en_profundidad(x *grafo, int tam, int inicio) {
	int visitados[tam];
	pila *p = NULL;
	int i, pos, y;
	x *aux;
	for (i = 0; i<tam; i++) {
		visitados[i] = 0;
	}
	p = apila(p, inicio);
	while (p != NULL) {
		pos = p->num;
		p = desapila(p);
		if (visitados[pos] != 1) {
			visitados[pos] = 1;
			printf(" %d ", pos);
		}
		aux = grafo[pos].prox;
		while (aux != NULL) {
			if (visitados[aux->num] != 1) {
				y = aux->num;
				p = apila(p, y);
			}
			aux = aux->prox;
		}
	}
}
/************************************************************/
centinela *inserta_fila(centinela *cent, int num) {
	pila *aux = (pila *)malloc(sizeof(pila));
	aux->num = num;
	aux->prox = NULL;
	if (cent->fin == NULL) {
		cent->inicio = aux;
		cent->fin = aux;
	}
	else {
		cent->fin->prox = aux;
		cent->fin = aux;
	}
	return cent;
}
/************************************************************/
centinela *desenfila(centinela *fila) {
	pila *aux;
	if (fila->inicio == fila->fin) {
		free(fila->inicio);
		fila->inicio = NULL;
		fila->fin = NULL;
	}
	else {
		aux = fila->inicio;
		fila->inicio = fila->inicio->prox;
		free(aux);
	}
	return fila;
}
/************************************************************/
void busqueda_por_anchura(x *grafo, int tam, int inicio) {
	int visitados[tam];
	centinela *cent = (centinela *)malloc(sizeof(centinela));
	cent->inicio = NULL;
	cent->fin = NULL;
	int i, pos, y;
	x *aux;
	for (i = 0; i<tam; i++) {
		visitados[i] = 0;
	}
	cent = inserta_fila(cent, inicio);
	while (cent->fin != NULL) {
		pos = cent->inicio->num;
		cent = desenfila(cent);
		if (visitados[pos] != 1) {
			visitados[pos] = 1;
			printf(" %d ", pos);
		}
		aux = grafo[pos].prox;
		while (aux != NULL) {
			if (visitados[aux->num] != 1) {
				y = aux->num;
				cent = inserta_fila(cent, y);
			}
			aux = aux->prox;
		}
	}
}
