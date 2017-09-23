#include <stdio.h>
#include <stdlib.h>
#define MAX 56
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

    procurandoMaiorPosi(vet, &j, &i, MAX);
    printf("\n\n\nO maior valor encontrado e: %d\nna posicao: %d", i,j);
}