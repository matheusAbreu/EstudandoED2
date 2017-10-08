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
    x->valor = 0.0f;
}
int testaGalhoInfoNula(tree *x)
{
    if(x->express == NULL && x->valor == 0.0f)
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
    }

    //else
      //  printf("\nA Arvore esta vazia\n");
}
void imprimindoArvore(tree *x, int nivel)
{
    char aux[50];
    int i;
    
    for(i = 0; i < nivel; i++)
        aux[i]='\t';
    
    aux[nivel] = '\0';
    
    if(testaGalhoInfoNula(x))
        printf("\n%sNULL", aux);
    else if(x->valor != 0.0f)
        printf("\n%s%.2f",aux, x->valor);
    else
        printf("\n%s%c", aux, x->express);
    
    if(x->esq != NULL)
        imprimindoArvore(x->esq, (nivel +1));
    
    if(x->dir != NULL)
        imprimindoArvore(x->dir, (nivel +1));
}
void imprimindoEmPosFixa(tree *x)
{
    if(x->dir != NULL)
    imprimindoEmPosFixa(x->dir);
    
    if(x->esq != NULL)
    imprimindoEmPosFixa(x->esq);
    
    if(x->express == NULL)
        printf("%.2f ", x->valor);
    else
        printf("%c ", x->express);
}
void escrevendoExpresao(tree *x, char *ex, int tam)// </editor-fold>

{
    int i, j = 0,k;
    tree *y, *pnt;
    char aux[tam], it;
    
    y = x;
    pnt = NULL;
    
    for(i = 0; i < tam; i++)
    {
         if(testaNumero(ex[i]))
         {
            aux[j]=ex[i];
            aux[j+1] = '\0';
            j++;
         }
         else if(ex[i] == '+' || ex[i] == '-')
         {
            y->dir=criandoRamo();
            y->esq=criandoRamo();
            escrevendoNULL(y->dir);
            y->dir->valor=atof(aux);
            for(k=0;k<j;k++)
                aux[k]='\0';

            j = 0;
            y->express = ex[i];
            escrevendoNULL(y->esq);
            y=y->esq;
         }
         else if(ex[i] == '*' || ex[i] == '/')
         {
            y->dir=criandoRamo();
            escrevendoNULL(y->dir);
            pnt = y;
            y = y->dir;
            y->dir=criandoRamo();
            escrevendoNULL(y->dir);
            y->dir->valor=atof(aux);
            for(k=0;k<j;k++)
                aux[k]='\0';
            j = 0;
            
            y->express = ex[i];
            i++;
            
            for(;i < tam;i++)
            {
                if(testaNumero(ex[i]))
                {
                   aux[j]=ex[i];
                   aux[j+1] = '\0';
                   j++;
                }else
                    break;
            }
            
            y->esq=criandoRamo();
            escrevendoNULL(y->esq);
            y->esq->valor=atof(aux);
            for(k=0;k<j;k++)
                aux[k]='\0';
            j = 0;
            
            y = pnt;
            pnt = NULL;
            
            y->esq=criandoRamo();
            escrevendoNULL(y->esq);
            y->express = ex[i];
            y=y->esq;
         }
        /* else
         {
            printf("\nErro na expressao\n");
            i =tam;
            cortandoGalho(x);
            x=criandoRamo();
            escrevendoNULL(x);            
         }*/
        
    }
    if(j > 0)
      y->valor=atof(aux);
    
    
}
int testaNumero(char x)
{
    if(x == '0' ||x == '1' ||x == '2' ||x == '3' ||x == '4' ||x == '5' ||x == '6' ||x == '7' ||x == '8' ||x == '9')
        return 1;
    else
        return 0;
}
float calculandoArvore(tree *x)
{
    float aux;
    if(x->valor != 0.0f)
        return x->valor;
    else if(x->express != NULL)
        switch(x->express)
        {
            case '+':
                aux =(calculandoArvore(x->dir) + calculandoArvore(x->esq));
            break;
            case '-':
                aux =(calculandoArvore(x->dir) - calculandoArvore(x->esq));
            break;
            case '*':
                aux =(calculandoArvore(x->dir) * calculandoArvore(x->esq));
            break;
            case '/':
                aux =(calculandoArvore(x->dir) / calculandoArvore(x->esq));
            break;
        }
    else
        return 0.0;

    return aux;
}