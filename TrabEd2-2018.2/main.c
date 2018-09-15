#include "ArvoreConta.h"
#include <string.h>
/*
 * 
 */
char *recebendoExpressao()
{
    int tam;
    char temp[10000], *expres;
    
    gets(temp);
    LIMBUF;
    
    tam = strlen(temp);
    if(tam > 2)
    {
        expres = NULL;
        expres = (char*)malloc((tam+1)*sizeof(char));
        
        if(expres != NULL)
        {
            strcpy(expres, temp);
            return expres;
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:recebendoExpressao\n");
    }
    else
            printf("\nHouve um erro na alocacao - Funcao:recebendoExpressao\n");

}
void main()
{
    char *y;
    printf("\n Simplesmente escreva\n ");
    y = recebendoExpressao();
    printf("\n Deixa eu ver o que eu escrevi:\n %s", y);
}

