/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TextComPali.h"

void limpandoMeuTexto(MeuTexto *x)
{
    free(x->posEsp);
    free(x->vetor);
    x->tam =0;  
    x->qntEsp = 0;    
}
MeuTexto *criandoMeuTexto()
{
    MeuTexto *x;
    
    x = (MeuTexto*)malloc(1*sizeof(MeuTexto));
    
    if(x ==NULL)
        printf("\nHouve um erro na alocacao - CriandoMeuTexto\n");
    
    return x;
}
void identificandoEspacos(MeuTexto *x)
{
    int temp[x->tam], i, qntEsp =0;
    
    for(i =0; i<x->tam;i++)
        if(x->vetor[i] == ' ')
            temp[qntEsp++] = i;
        
    free(x->posEsp);
    x->posEsp = (int*)malloc(qntEsp*sizeof(int));
    
    if(x->posEsp != NULL)
    {
        for(i=0;i < qntEsp;i++)
            x->posEsp[i] = temp[i];

        x->qntEsp = qntEsp ;
    }
    else
        printf("\nHouve um erro na alocacao - Funcao:criandoEspaco\n");
    
    
}
void escrevendoMeuTexto(MeuTexto *x)
{
    int tam,i;
    char temp[10000];
    
    gets(temp);
    LIMP;
    
    tam = strlen(temp);
    if(tam > 2)
    {
        limpandoMeuTexto(x);
        x->vetor = (char*)malloc((tam+1)*sizeof(char));
        
        if(x->vetor != NULL)
        {
            x->tam = tam;
            strcpy(x->vetor, temp);
            identificandoEspacos(x);
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");
    }
    else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");
}
void copiandoMeuTexto(MeuTexto *dest, MeuTexto *ori, int ini, int fim)
{
    int i;
    
        limpandoMeuTexto(dest);
        dest->vetor = (char*)malloc((fim-ini+1)*sizeof(char));
        if(dest->vetor != NULL)
        {
            dest->tam = (fim-ini)+1;
            for(i =ini; i<fim;i++)
                dest->vetor[i-ini] = ori->vetor[i];
                    
            identificandoEspacos(dest);
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");
    
}
void imprimindoMeuTexto(MeuTexto *x)
{
    int i;
    printf("\n\nTamanhoda String: %d\nA String armazenada e: \"%s\"\nContendo %d espacos, nas casas:",x->tam, x->vetor,x->qntEsp);
    for(i = 0;i<x->qntEsp;i++)
        printf((i==(x->qntEsp-1))?(" %d\n\n"):(" %d,"),x->posEsp[i]);
}