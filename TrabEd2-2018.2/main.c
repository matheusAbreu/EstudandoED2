#include "ArvoreConta.h"
/*
 * 
 */

void main()
{
    texto *t;
    tree *test;
    printf("\n Simplesmente escreva\n ");
    t = recebendoExpressao();
    printf("\n Deixa eu ver o que eu escrevi:\n");
    imprimindoTexto(t);
    
    test = escrevendoArvoreExec(t);
    imprimindoArvore(test,0);
}

