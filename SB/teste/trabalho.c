#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct Tmemoria
{
	int cheio;
	int tam;
	int *espaco;
	struct Tmemoria *prox;
} Tmemoria;

void *inicioHeap;
void *topoInicialHeap;
void *valorAnteriorHeap;

Tmemoria *inicioBegin;	//inicio da lista
Tmemoria *topoHeap;	    //fim da lista

void iniciaAlocador ()  //esta funcao esta pronta
{
	valorAnteriorHeap = topoInicialHeap;
	topoInicialHeap = sbrk (0);
	inicioHeap = topoInicialHeap;
	inicioBegin = NULL;
	topoHeap = NULL;
}

void finalizaAlocador ()
{
	topoInicialHeap = valorAnteriorHeap;
}

// int liberaMem (void *bloco)
// {

// }

void *alocaMem (int num_bytes)
// {
// 	void *aux;
// 	Tmemoria aux2, *aux3;

// 	aux2.cheio = 1;
// 	aux2.tam = num_bytes;
// 	aux2.espaco = malloc (num_bytes);
// 	aux2.prox = NULL;
	__asm__("

		")

// 	if (! (inicioBegin) && ! (topoHeap))
// 	{
// 		printf ("%d\n", topoInicialHeap);
// 		inicioBegin = topoInicialHeap;
// 		topoInicialHeap = topoInicialHeap + (sizeof (Tmemoria));
// 		printf ("%d\n", topoInicialHeap);
// 		memcpy (inicioBegin, aux2, sizeof (Tmemoria));
// 		printf ("O espaço alocado foi de: %d\n", inicioBegin -> tam);
// 		topoHeap = inicioBegin;
// 		return;
// 	}

// 	aux3 = inicioBegin;

// 	while (aux3 -> prox != NULL)
// 	{
// 		if (aux3 -> cheio == 0 && aux3 -> tam >= num_bytes)
// 		{

// 		}
// 		aux3 = aux3 -> prox;
// 	}
}

int main ()
{
	int n;
	iniciaAlocador ();
	printf("Entre com um valor : ");
	scanf ("%d", &n);
	alocaMem (n);
	return 0;
}