#include <stdio.h>
#include <stdlib.h>
#include "Ordenadores.h"

item *CriandoItem()
{
    item *x;

    x = (item*)malloc(1*sizeof(item));

    if(x != NULL)
    {
        x->valor = 0;
        x->prox = NULL;
    }
    else
    {
        printf("\nHouve um erro na alocacao - CriandoItem\n");
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
        aux->valor = NULL;
        aux->prox = NULL;
        free(aux);
    }
    else
    {
        x->valor = NULL;
        x->prox = NULL;
        free(x);
        x = NULL;
    }
}
item *ApagandoLista(item *x)
{
    for(; x != NULL; x = x->prox)
        ApagandoItem(x);

    return NULL;
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
    {
        cont = x;
        do
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
            cont = cont->prox;
        }while(cont != NULL);
    }
    else
        printf("\nA Lista está Vazia!\n");
}
