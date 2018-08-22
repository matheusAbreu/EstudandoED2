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
    MeuTexto *y;
    y = crinadoMeuTexto();
    printf("Escreva seu texto:\n\n");
    
    escrevendoMeuTexto(y);
    printf("\n\nVerifique o que salvamos\n\n");
    imprimindoMeuTexto(y);
    limpandoMeuTexto(y);
    free(y);
}

