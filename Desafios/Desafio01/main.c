/* 
 * File:   main.c
 * Author: lema
 *
 * Created on 20 de Agosto de 2018, 20:59
 */

#include <stdio.h>
#include <stdlib.h>

#if linux
#define LIMP __fpurge(stdin)
#endif
#if WIN32
#define LIMP fflush(stdin)
#endif

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
    printf("\nResultado:\n");
    for(i = 0; i < tam; i++)
        for(j = (tam-1); j >= i; j--)
        {
            if((vet[i]+vet[j]) == total)      
                printf ("Posicoes %d e %d\n", i,j);
            
        }
}

void main(int argc, char** argv) 
{
    int *vetor, total, tam, i;
    
    srand((unsigned) time NULL);
    
    /*
        tam = (rand()%100);
        total =(rand()%100);
    */
    
    printf("\nPor favor, insira o tamanho do vetor:\n");
    scanf("%i", &tam);
    LIMP;
    
    printf("Qual valor deseja tentar encontrar?(Randomizados sao todos menores que 100)\n");
    scanf("%i", &total);
    LIMP;
    
    vetor = createVetorInt(tam);
    printf("Vetor criando!\nGereando numeros e realizando busca...\n");
    for(i =0; i < tam;i++)
    {
        vetor[i] = (rand()%100);
        printf((i<10)?("vetor[0%d] = %d\n"):("vetor[%d] = %d\n"), i, vetor[i]);
        
        if(i%10 == 0 && i != 0)
            printf("\n");
    }
    printf("\nO total = %d\n\n\n", total);
    busqueSoma(total,vetor,tam);
}

