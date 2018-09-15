#include "ArvoreConta.h"

struct ARVORE_CONTA
{
    float valor;
    char express;
    struct ARVORE_CONTA *dir, *esq;
}typedef tree;

tree *criandoRamo()
{
    tree *x;
    x = (tree*)malloc(1*sizeof(tree));
    if(x != NULL)
        return x;
    else
        printf("\nHouve um erro na alocacao - Funcao:CriandoRamo\n");
}
void anulandoRamo(tree *x)
{
    x->valor = 0.0f;
    x->express = NULL;
    x->dir = NULL;
    x->esq = NULL;
}
