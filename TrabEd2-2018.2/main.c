#include "ArvoreConta.h"
/*
 * 
 */

void main()
{
    texto *t;
    tree *test;
    float result;
    
    int i;
    printf("\n Simplesmente escreva\n ");
    t = recebendoExpressao();
    printf("\n Deixa eu ver o que eu escrevi:\n");
    imprimindoTexto(t); 
    
    test = escrevendoArvoreExec(t);
    imprimindoArvore(test,0);
    printf("\n\n");
    imprimindoArvorePosFixa(test);
    
    result = calculandoArvore(test);
    printf("\nResultado = %.2f", result);
    
    liberandoArvore(test);
    apagandoTexto(t);
}

