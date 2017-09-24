#include "procurando.h"
void ordenandoInteirosCresc(int *x, int tam)//Analise do cod 00
{
    int posTemp, valorTemp,j, aux[tam];
    
   for(j = 0; j < tam ; j++)
    {   
      procurandoMenorPosi(x, &posTemp, &valorTemp, tam);
      
      aux[j] = valorTemp;
      x[posTemp] = (tam*10000);
      posTemp =0;
      valorTemp = 0;
      
      /*O teste abaixo, teoricamente, posibilitaria que a ordenação ocorresse no momento da leitura
       * porém não consegui torna-lo efetivo, problemas encontrados:
       * copiar numeros
       * pular valores na ordenação
        
       Se estivesse funcionando não precisaria de um vetor auxiliar, e com isso, tbm poderia ser discartado o for final
      if(x[j]> x[(posTemp+j)])
      {
        aux = x[j];
        x[j] = valorTemp;
        x[(posTemp+j)] = aux;
        aux = 0;
      }*/
    }
    for(j=0;j<tam;j++)
        x[j] = aux[j];
   
}
void ordenandoInteirosDecresc(int *x, int tam)
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