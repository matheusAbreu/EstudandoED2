/* 
 * File:   main.c
 * Author: lema
 *
 * Created on 21 de Agosto de 2018, 16:06
*/
#include "TextComPali.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
    MeuTexto *y, *pali;
    int ini, fim;
    y = criandoMeuTexto();
    printf("\nManual:\n");
    printf("1 - Nao use letras maisculas\n");
    printf("2 - Nao utilize acentos\n");
    printf("3 - pontuações, parenteses, colchetes, chaves, arroba, sharp e espacos serao ignorados na comparação palindrica\n");
    printf("\nEscreva seu texto:\n");
    escrevendoMeuTexto(y);
    printf("\nVerifique o que salvamos\n");
    
    imprimindoMeuTexto(y);
    printf("\nVeja esse o maior palindromo que pegamos do seu texto:");
    
    pali = procurandoMaiorPalindro(y);
    imprimindoMeuTexto(pali);
    printf("\n\n\n");
    //Fechando o programa
    limpandoMeuTexto(y);
    limpandoMeuTexto(pali);
    free(pali);
    free(y);
}

