#include "procurando.h"
#include <stdio.h>
#include <stdlib.h>
void ordenandoInteirosCresc(int *x, int tam)//Algoritmo de ordenação tipo bolha
{//Esse algoritmo segundo o slide é um (n²-n)/2
    int i,j, aux;
    
   for(j = tam; j >=1 ; j--)//Segundo o metodo dispoto, temos que percorrer a lista n vezes
       for(i = 1; i<tam; i++)//E em nossa comparativa, por pularmos o primeiro index, graças ao tipo de compração temos (n -1) comparações
           if(x[i] < x[i-1])//Logica da solução: compare um index com o anterior, caso seja menor, troca
           {
               aux = x[i];
               x[i]= x[i-1];
               x[i-1] = aux;
              // imprimindoVet(x, tam); //impressao auxiliar
           }
       
   //
}
void ordenandoInteirosDecresc(int *x, int tam)//Analise do cod 00
{
    int posTemp, valorTemp,j, aux[tam];
    
   for(j = 0; j < tam ; j++)
    {   
      procurandoMaiorPosi(x, &posTemp, &valorTemp, tam);
      
      aux[j] = valorTemp;
      x[posTemp] = (tam*-10000);
      posTemp =0;
      valorTemp = 0;
      
    }
    for(j=0;j<tam;j++)
        x[j] = aux[j];
   
}
void shellSort(int *vet, int n)
{
    int i, j, h =1, item;
    
    do
        h = h*3;
    while(h < n);
    do
    {
        h /= 3;
        for(i=h;i<=n;i++)
        {
            item = vet[i];
            j = i;
            while(vet[j-h] > item)
            {
                vet[j] = vet[j-h];
                j -= h;
                if(j <= h)
                    break;
            }
            vet[j]=item;
            
            imprimindoVet(vet, 20);
            printf("\n\n");
        }
    }while(h != 0);
}