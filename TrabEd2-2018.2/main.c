#include "ArvoreConta.h"
/*
 * 
 */

void main()
{
    texto *y;
    tree *test;
    printf("\n Simplesmente escreva\n ");
    y = recebendoExpressao();
    printf("\n Deixa eu ver o que eu escrevi:\n");
    imprimindoTexto(y);
    
    imprimindoArvore(test,0);
}

