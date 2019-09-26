#include <stdio.h>
#include <stdlib.h>
#include "Ordenadores.h"

item *CriandoItem()
{
    item *x;

    x = (item*)malloc(1*sizeof(item));

    if(x == NULL)
    {
        printf("\nHouve um erro na alocacao - CriandoItem\n");
    }
    else
    {
        x->valor = 0;
        x->prox = NULL;
    }
    return x;
}
void ApagandoItem(item *x)
{
   item *aux;

    if(x->prox != NULL)
    {
        aux = x;
        x = x->prox;
        free(aux);
    }
    else
    {
        free(x);
        x = NULL;
    }
}
void ApagandoLista(item *x)
{
    for(; x != NULL; x = x->prox)
        ApagandoItem(x);
}
item *CriandoListaRand(int qntitens, int randMax)
{
    srand((unsigned) time(NULL));

    int i;
    item *x, *aux;
    x = aux = CriandoItem();

    for(i = 0; i < qntitens; i++)
    {
        aux->valor = (rand() % randMax);
        aux->prox = CriandoItem();
        aux = aux->prox;
    }
    aux->valor = (rand() % randMax);
    return x;
}
void ImprimindoListaItem(item *x)
{
    int i = 0;
    item *cont;
    if(x != NULL)
        for(cont = x; cont != NULL; cont = cont->prox)
        {
            if(i < 10)
            {
                 printf("%d - ", cont->valor);
                 i++;
            }
            else
            {
                printf("%d\n", cont->valor);
                i = 0;
            }
        }
    else
        printf("A Lista está Vazia!");
}
