#include <stdio.h>
#include <stdlib.h>
#include "funcoes_abb.h"
#include "funcoes_avl.h"
#include "arvore.h"

// impressão de dados do nó
void visita (struct no_arvore *no){
	int alt = altura_no(no);
	printf ("%d,%d\n", no -> chave, alt);
}
// impressão da árvore em pré-ordem
void pre_ordem (struct no_arvore *no){
	if (no != NULL){
		visita(no);
		pre_ordem(no -> esq);
		pre_ordem(no -> dir);
	}
}
// impressão da árvore em ordem
void em_ordem (struct no_arvore *no){
	if (no != NULL){
		em_ordem(no -> esq);
		visita(no);
		em_ordem(no -> dir);
	}
}
// impressão da árvore em pós-ordem
void pos_ordem (struct no_arvore *no){
	if (no != NULL){
		pos_ordem(no -> esq);
		pos_ordem(no -> dir);
		visita(no);
	}
}
// cálculo da alt da raiz até a folha
int altura_arvore (struct no_arvore *no){
	int hE, hD;
	if (no == NULL)
		return 0;
	else{
		//visita (no);
		hE = altura_arvore(no -> esq);
		hD = altura_arvore(no -> dir);

		if (hE > hD)
			return hE + 1;
		else
			return hD + 1;
	}
}