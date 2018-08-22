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
MeuTexto *crinadoMeuTexto()
{
    MeuTexto *x;
    
    x = (MeuTexto*)malloc(1*sizeof(MeuTexto));
    
    if(x ==NULL)
        printf("\nHouve um erro na alocacao - CriandoMeuTexto\n");
    
    return x;
}
void criandoEspacos(MeuTexto *x, int novEsp)
{
    int *temp, i = x->qntEsp;
    temp = (int*)malloc((i+1)*sizeof(int));
    
    if(temp != NULL)
    {
        for(i=0;i<x->qntEsp;i++)
            temp[i] = x->posEsp[i];
        
        free(x->posEsp);
        temp[x->qntEsp] = novEsp;
        x->posEsp = temp;
        x->qntEsp++;
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
    printf("\n%d\n", tam);
    if(tam > 2)
    {
        limpandoMeuTexto(x);
        x->vetor = (char*)malloc((tam+1)*sizeof(char));
        if(x->vetor != NULL)
        {
            x->tam = tam;
            strcpy(x->vetor, temp);
            for(i =0; i<tam;i++)
                if(x->vetor[i] == ' ')
                    criandoEspacos(x,i);
               
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:escrevendoMeuTexto\n");
    }
}
void imprimindoMeuTexto(MeuTexto *x)
{
    int i;
    printf("\n\nTamanhoda String: %d\nA String armazenada e: \"%s\"\nContendo %d espacos, nas casas:",x->tam, x->vetor,x->qntEsp);
    for(i = 0;i<x->qntEsp;i++)
        printf((i==(x->qntEsp-1))?(" %d\n\n"):(" %d,"),x->posEsp);
}