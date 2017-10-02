#include <stdio.h>
#include <stdlib.h>

#include "ArvoreDeExecucao.h"
tree *criandoRamo()
{
    tree *novo;
    
    novo = (tree*)malloc(1*sizeof(tree));
    
    if(novo == NULL)
    {
        printf("\nErro de alocacao\n");
        return NULL;
    }
    else 
        return novo;
}
void escrevendoNULL(tree *x)
{
    x->dir = NULL;
    x->esq = NULL;
    x->express = NULL;
    x->valor = NULL;
}
int testaGalhoInfoNula(tree *x)
{
    if(x->express == NULL && x->valor == NULL)
        return 1;
    else
        return 0;
}
void cortandoGalho(tree *x)
{
    if(x != NULL)
    {
        if(x->dir != NULL)
            cortandoGalho(x->dir);
        
        if(x->esq != NULL)
            cortandoGalho(x->esq);
        
        free(x);
        x = NULL;
    }
    else
        printf("\nA Arvore esta vazia\n");
}
void imprimindoArvore(tree *x, int nivel)
{
    char aux[50];
    int i;
    
    for(i = 0; i < nivel; i++)
        aux[i]='\t';
    
    aux[nivel] = '\0';
    
    if(testaGalhoInfoNula(x))
        printf("\n%sValor Nulo", aux);
    else if(x->valor != NULL)
        printf("\n%s%d",aux, x->valor);
    else
        printf("\n%s%s", aux, x->express);
    
    if(x->esq != NULL)
        imprimindoArvore(x->esq, (nivel +1));
    
    if(x->dir != NULL)
        imprimindoArvore(x->dir, (nivel +1));
}