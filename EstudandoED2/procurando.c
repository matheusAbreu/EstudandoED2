/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


int procurandoOMaior(int *x, int tam)
{
    int maior = x[0], j, temp =0;

    if((tam %2)==0)
    {
         for(j =2; j < tam; j +=2)
        {
            if(x[j]>x[j-1])
                temp = x[j];
            else
                temp = x[j-1];


            if(temp > maior)
                maior = temp;
        }
         if(x[tam -1] > maior)
                maior = temp;
    }
    else
    {
         for(j =2; j < (tam -1); j +=2)
        {
            if(x[j]>x[j-1])
                temp = x[j];
            else
                temp = x[j-1];


            if(temp > maior)
                maior = temp;
        }
        
    }
    return maior;
}
void procurandoMaiorPosi(int *x, int *pos, int *maior,int tam)
{
    int j, temp =0, posTemp;
    *maior = x[0];
    
    if((tam %2) == 0)
    {
         for(j =2; j < tam; j +=2)
        {
            if(x[j] > x[j-1])
            {
                temp = x[j];
                posTemp = j;
            }
            else
            {
                temp = x[j-1];
                posTemp = (j - 1);
            }

            if(temp > *maior)
            {
                *maior = temp;
                *pos = posTemp;
            }
        }
         if(x[tam -1] > *maior)
         {
             *pos = (tam - 1);
             *maior = temp;
         }
    }
    else
    {
         for(j =2; j < (tam -1); j +=2)
        {
            if(x[j]>x[j-1])
            {
               temp = x[j];
               posTemp = j;
            }
            else
            {
               temp = x[j-1];
               posTemp = (j - 1);
            }

            if(temp > *maior)
            {
                *maior = temp;
                *pos = posTemp;
            }
        }
        
    }
}
void procurandoMenorPosi(int *x, int *pos, int *menor,int tam)
{
    int j, temp =0, posTemp;
    *menor = x[0];
    
    if((tam %2)==0)
    {
         for(j =2; j < tam; j +=2)
        {
            if(x[j] < x[j-1])
            {
                temp = x[j];
                posTemp = j;
            }
            else
            {
                temp = x[j-1];
                posTemp = (j - 1);
            }

            if(temp < *menor)
            {
                *menor = temp;
                *pos = posTemp;
            }
        }
         if(x[tam -1] < *menor)
         {
             *pos = (tam - 1);
             *menor = temp;
         }
    }
    else
    {
         for(j =2; j < (tam -1); j +=2)
        {
            if(x[j] < x[j-1])
            {
               temp = x[j];
               posTemp = j;
            }
            else
            {
               temp = x[j-1];
               posTemp = (j - 1);
            }

            if(temp < *menor)
            {
                *menor = temp;
                *pos = posTemp;
            }
        }
        
    }
}
int procurandoOMenor(int *x, int tam)
{
    int menor = x[0], j, temp =0;

    if((tam %2)==0)
    {
         for(j =2; j < tam; j +=2)
        {
            if(x[j]<x[j-1])
                temp = x[j];
            else
                temp = x[j-1];


            if(temp < menor)
                menor = temp;
        }
         if(x[tam -1] < menor)
                menor = temp;
    }
    else
    {
         for(j =2; j < (tam -1); j +=2)
        {
            if(x[j]<x[j-1])
                temp = x[j];
            else
                temp = x[j-1];


            if(temp < menor)
                menor = temp;
        }
        
    }
    return menor;
}
int procurandoChave(int *x, int tam)
{
    int chave, j, temp;
    
    scanf("%i", &chave);

    if(chave == x[0])
        temp = 0;
    else if((tam %2)==0)
    {
         if(x[tam -1] == chave)
            temp = (tam - 1);
        else 
        {
            temp = -1;
             
            for(j =2; j < tam; j +=2)
           {
               if(x[j] == chave)
               {
                   temp = j;
                   break;
               }
               else if(x[j-1] == chave)
               {
                   temp = (j-1);
                   break;
               }            
           }
        }
    }
    else
    {
        temp = -1;
        for(j =2; j < (tam -1); j +=2)
        {
           if(x[j] == chave)
            {
                temp = j;
                break;
            }
            else if(x[j-1] == chave)
            {
                temp = (j-1);
                break;
            }   
        }        
    }
    if(temp>=0)
        temp ++;
    return temp;
}
void procurandoMaioMenor(int *vet, int *men, int *mai, int tam)
{
     int j, tempMaior =vet[0], tempMenor = vet[0];

    if((tam %2)==0)
    {
        for(j =2; j < tam; j +=2)
        {
            if(vet[j]>vet[j-1])
            {
                if(vet[j] > tempMaior)
                    tempMaior = vet[j];
                
                if(vet[j-1] < tempMenor)
                    tempMenor = vet[j-1];
                
            }
            else
            {
                if(vet[j] > tempMaior)
                    tempMaior = vet[j-1];
                
                if(vet[j-1] < tempMenor)
                    tempMenor = vet[j];
            }
        }
        if(vet[tam -1] > tempMaior)
             tempMaior = vet[tam -1];
                
        else if(vet[tam -1] < tempMenor)
             tempMenor = vet[tam -1];
    }
    else
    {
         for(j =2; j < tam; j +=2)
        {
            if(vet[j]>vet[j-1])
            {
                if(vet[j] > tempMaior)
                    tempMaior = vet[j];
                
                if(vet[j-1] < tempMenor)
                    tempMenor = vet[j-1];
                
            }
            else
            {
                if(vet[j] > tempMaior)
                    tempMaior = vet[j-1];
                
                if(vet[j-1] < tempMenor)
                    tempMenor = vet[j];
            }
        }
        
    }
     *men = tempMenor;
     *mai = tempMaior;
}