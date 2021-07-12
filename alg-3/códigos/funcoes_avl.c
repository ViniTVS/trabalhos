#include <stdio.h>
#include <stdlib.h>
#include "funcoes_abb.h"
#include "funcoes_avl.h"
#include "arvore.h"

// criação de um nó AVL
struct no_arvore * cria_no (int ent){
	// faço a alocação de memória de um novo nó
	struct no_arvore *no = (struct no_arvore *)malloc(sizeof (struct no_arvore));
	// testo se a alocação foi feita
	if (no == NULL){ 
		printf("!ERRO!\nNó de %d não foi alocado!\n", ent);
		return NULL;
	}

	no -> chave  = ent;
	no -> esq    = NULL;
	no -> dir    = NULL;
	no -> altura = 0;
	no -> pai    = NULL;
	// como é um nó folha, todos seus ponteiros serão p/ NULL e sua altura 0
	return no;
}

// correção da altura de nó da AVL
void corrige_altura (struct no_arvore *no){
	// calculo a altura dos nós filhos e retorno a diferença (direita - esquerda)
	int hE, hD;
	hE = altura_arvore (no -> esq);
	hD = altura_arvore (no -> dir);
	no -> altura = (hD - hE);
}

// correção recursiva de toda a árvore/subarvore com base em sua altura
struct no_arvore * corrige_arv (struct no_arvore *raiz){
	if (raiz == NULL)
		return raiz;

	struct no_arvore *aux = raiz;
	//corrijo a altura do nó atual
	corrige_altura (aux);
	
	// caso preciso, faço uma rotação e faço uma segunda verificação 
	if (aux -> altura > 1){
		aux = rot_esq (aux);
		corrige_altura (aux);
		raiz = corrige_arv (raiz);
	}

	if (aux -> altura < -1){
		aux = rot_dir (aux);
		corrige_altura (aux);
		raiz = corrige_arv (raiz);
	}

	// realizo a correção dos filhos
	aux -> esq = corrige_arv(aux -> esq);
	aux -> dir = corrige_arv(aux -> dir);
}

struct no_arvore * rot_esq (struct no_arvore *no){
	struct no_arvore *aux = no -> dir;
	// no caso de dir esq:
	if (aux != NULL && aux -> altura <= -1)
	 	aux = rot_dir (aux);
	
	// aux -> pai recebe no -> pai e vice-versa
	if (no -> pai != NULL){
		if (no -> pai -> esq == no) // testo se o nó é filho esq ou dir	
			no -> pai -> esq = aux;
		else
			no -> pai -> dir = aux;
	}
	aux -> pai = no -> pai;

	// aux -> esq vira filho de nó
	if (aux -> esq != NULL)
		aux -> esq -> pai = no;
	no -> dir = aux -> esq;

	// nó vira filho dir de aux
	aux -> esq = no;
	no -> pai = aux;

	// testo se é preciso de uma 2a rotação tanto no nó quanto no aux
	corrige_altura(aux);
	corrige_altura(no);
	
	return aux;
}

struct no_arvore * rot_dir (struct no_arvore *no){
	struct no_arvore *aux = no -> esq;
	// no caso de esq dir:
	if (aux != NULL && aux -> altura >= 1)
	 	aux = rot_esq (aux);
	
	// aux -> pai recebe no -> pai e vice-versa
	if (no -> pai != NULL){
		if (no -> pai -> esq == no) // testo se o nó é filho esq ou dir	
			no -> pai -> esq = aux;
		else
			no -> pai -> dir = aux;
	}
	aux -> pai = no -> pai;

	// aux -> dir vira filho de nó
	if (aux -> dir != NULL)
		aux -> dir -> pai = no;
	no -> esq = aux -> dir;

	// nó vira filho dir de aux
	aux -> dir = no;
	no -> pai = aux;
	
	// corrijo alturas e se é preciso de uma 2a rotação tanto no nó quanto no aux
	corrige_altura(aux);
	corrige_altura(no);

	return aux;
}

// Inserção recursiva de nós
struct no_arvore * insere_arvore (struct no_arvore *raiz, int ent) {
	struct no_arvore *no = raiz;
	// ao estar em um NULL, crio este nó
	if (no == NULL){
		no = cria_no (ent);
		return no;
	}
	// teste p/ caso tente inserir um nó que já existe
	if (ent == no -> chave){
		printf("Nó de %d já existente\n", no -> chave);
		return no;
	}
	// vou p/ a esq ou dir caso a chave a ser inseria seja menor ou maior, respectivamente
	// e faço a correção do pai do nó inserido
	if (ent < no -> chave){
		no -> esq = insere_arvore (no -> esq, ent);
		no -> esq -> pai = no;
	}
	else{
		no -> dir = insere_arvore (no -> dir, ent);
		no -> dir -> pai = no;
	}

	// Correção de altura do nó atual por causa da inserção de um novo elemento	
	corrige_altura (no);
	// e faço a rotação caso necessário
	if (no -> altura < -1)
		no = rot_dir(no);

	if (no -> altura > 1)
		no = rot_esq(no);
	
	return no;
}

// remoção recursiva de nós
struct no_arvore * remove_no (struct no_arvore *no, int valor){
	// teste p/ caso tente fazer a exclusão de um nó inexistente
	if (no == NULL){
		printf("Nó %d inexistente para remoção \n", valor);
		return no;
	}
	struct no_arvore *aux = NULL;
	// se for esta a chave que procuro:
	if (valor == no -> chave) {
		// se o nó não tiver filhos, basta retornar um NULL
		if (no -> esq == NULL && no -> dir == NULL){
			free (no);
			return aux;			
		}
		// se só a esquerda do nó for NULL:
		if (no -> esq == NULL){
			// seu pai passa a apontar p/ o nó dir
			aux = no -> dir;
			aux -> pai = no -> pai;
			//
			free (no);
			corrige_altura (aux);
			return (aux);
		}
		// se a esq do nó não for NULL:
		else{
			// aux vai p/ o antecessor direto do no
			aux = no -> esq;
			while (aux -> dir != NULL){
				aux = aux -> dir;
			}

			// o "antigo pai" de aux passa a opontar p/ NULL
			if (aux -> pai != NULL && aux -> pai -> esq == aux)
				aux -> pai -> esq = NULL;
			else if (aux -> pai != NULL)
				aux -> pai -> dir = NULL;
				
			// pai de aux aponta p/ pai do no
			aux -> pai = no -> pai;

			if (aux != no -> esq){	// evito que o aux aponte p/ si mesmo
				aux -> esq = no -> esq;
				aux -> esq -> pai = aux;

			}
			// aux dir recebe nó dir
			aux -> dir = no -> dir;
			if (aux -> dir != NULL)
				aux -> dir -> pai = aux;

			free (no);
			corrige_altura (aux);
			return (aux);
		}
	}
	else{	//valor a ser removido não foi encontrado no momento
		if (valor > no -> chave)
			no -> dir = remove_no(no -> dir, valor);
		else
			no -> esq = remove_no(no -> esq, valor);

		corrige_altura (no);
		return no;
		// por ser recursivo, no final a altura de todos os nós percorridos são ajustadas
		// e o pai do nó passa a apontar ao que tornará o lugar daquele a sex excluido
	}
}

// cálculo da altura de um nó até a raiz
int altura_no (struct no_arvore *no){
	struct no_arvore *aux = no;
	int val = 0;
	while (aux -> pai != NULL){
		aux = aux -> pai;
		val++;
	}
	return val;
}