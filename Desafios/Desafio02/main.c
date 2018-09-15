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
    printf("1 - Não use letras maiúsculas\n");
    printf("2 - Não utilize acentos\n");
    printf("3 - Pontuações, parênteses, colchetes, chaves, arroba, sharp e/ou espaços serão ignorados na comparação palíndrica\n");
    printf("4 - O Texto tem que ter menos que 10.000 caracteres\n");
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

