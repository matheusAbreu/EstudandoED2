/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lema
 *
 * Created on 20 de Agosto de 2018, 20:59
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int *createVetorInt(int tam)
{
    int *aux;
    
    aux = (int)malloc(tam*sizeof(int));
    if(aux == NULL)
    {
        printf("\nPerdão, houve um erro de alocacao\n O programa sera encerrado!\n");
        exit(0);
    }
    return aux;
}
void busqueSoma(int total, int *vet, int tam)
{
    int i,j;
    
    for(i = 0; i < tam; i++)
        for(j = (tam-1); j >= 0; j--)
        {
            printf ("i=%d j=%d\n", i,j);
        }
    
}
void main(int argc, char** argv) 
{
    int *vetor, total, tam;
    busqueSoma(0,vetor,10);
}

