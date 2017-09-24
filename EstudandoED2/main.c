#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#include "procurando.h"
#include "uni3.h"

void main()
{
    srand(time(NULL));
    int vet[MAX], i,j;

    for(i =0; i < MAX; i++)
    {
        if((i%10)==0 && i !=0)
            printf("\n");
        
        vet[i] = (rand()%1000);
        printf("%d\t",vet[i]);

    }
    printf("\n\n\n\n\n");
    
       
    ordenandoInteirosCresc(vet, MAX);
    imprimindoVet(vet, MAX);
     
}