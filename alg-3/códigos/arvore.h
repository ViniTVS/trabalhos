#ifndef _ARVORE_
#define _ARVORE_

struct no_arvore {
    int chave;
    struct no_arvore *pai;
    struct no_arvore *esq;
    struct no_arvore *dir;
    int altura;
};

#endif