/* 
 * File:   main.c
 * Author: lema
 *
 * Created on 21 de Agosto de 2018, 16:06
 */
#include "TextComPali.h"

/*
 * 
 */
void main()
{
    MeuText *x;
    
    printf("escreva o seu texto:\n");
    
    x = escreveMeuText();
    
    printf("\n veja o texto que salvamos:\n");
    
    imprimindoMeuText(x);
    
}

