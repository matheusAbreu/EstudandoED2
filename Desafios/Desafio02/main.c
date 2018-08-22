/* 
 * File:   main.c
 * Author: lema
 *
 * Created on 21 de Agosto de 2018, 16:06
 */
#include "TextComPali.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void main()
{
    MeuTexto *y,*cpy;
    int ini, fim;
    y = criandoMeuTexto();
    cpy = criandoMeuTexto();
    printf("Escreva seu texto:\n\n");
    
    escrevendoMeuTexto(y);
    printf("\n\nVerifique o que salvamos\n\n");
    
    imprimindoMeuTexto(y);
    printf("\n\nVeja esse trexo que pegamos do seu texto\n\n");
    
    
    printf("\nOnde vc que começar a retirar o texto: escolha um dos intervalos abaixo\n");
    scanf("%i",&ini); LIMP;
    printf("\nOnde vc que temine a retirada o texto: escolha um dos intervalos abaixo\n");
    scanf("%i",&fim); LIMP;
    copiandoMeuTexto(cpy,y,ini,fim);
    imprimindoMeuTexto(cpy);
    
    
    //Fechando o programa
    limpandoMeuTexto(y);
    limpandoMeuTexto(cpy);
    free(cpy);
    free(y);
}

