#ifndef _FUNCOES_ABB_
#define _FUNCOES_ABB_
#include "arvore.h"

void visita (struct no_arvore *no);

void pre_ordem (struct no_arvore *no);

void em_ordem (struct no_arvore *no);

void pos_ordem (struct no_arvore *no);

int altura_arvore (struct no_arvore *no);

#endif