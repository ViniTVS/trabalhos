#ifndef _FUNCOES_AVL_
#define _FUNCOES_AVL_
#include "arvore.h"
#include "funcoes_abb.h"

struct no_arvore * cria_no (int ent);

void corrige_alt_no (struct no_arvore *no);

struct no_arvore * corrige_arv (struct no_arvore *no);

void corrige_alt_no (struct no_arvore *no);

struct no_arvore * rot_dir (struct no_arvore *no);

struct no_arvore * rot_esq (struct no_arvore *no);

void corrige (struct no_arvore *no);

struct no_arvore * insere_arvore (struct no_arvore *no, int ent);

struct no_arvore * remove_no (struct no_arvore *no, int valor);

int altura_no (struct no_arvore *no);

#endif