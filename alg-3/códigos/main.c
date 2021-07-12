#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes_abb.h"
#include "funcoes_avl.h"
#include "arvore.h"

void main (){
    struct no_arvore *root = NULL;
    char op;
    int val;
    // scan do arquivo de entrada
    while ( (scanf( " %c" "%d" , &op, &val)) >= 0){
        if (op == 'i'){
            root = insere_arvore (root, val);
        }
        else{
            if (op == 'r'){
                // printf("farei remoção\n");
                root = remove_no (root, val);
                // correção de toda a árvore pois uma remoção pode desequilibrar a árvore
                root = corrige_arv (root);
            }
            else{
                printf("Operação não encontrada, saindo...\n");
                break;
            }
        }
    }

    em_ordem (root);
}