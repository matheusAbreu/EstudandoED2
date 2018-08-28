#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreDeExecucao.h"

void main()
{
    int i;
    char express[MAX];
    tree *test;
    test = criandoRamo();
    escrevendoNULL(test);

    printf("Por favor, escreva a expressao desejada:\n");
    scanf("%s", express);
    LIMBUF;
    CLS;
    i = strlen(express);
    printf("Escrevendo Arvore de execussao\n");
    escrevendoExpresao(test, express,i);
    imprimindoArvore(test,0);
    printf("\n\nEscrevendo a notacao pos-fixa da expressao\n\n");
    imprimindoEmPosFixa(test);
    printf("\n\n");
    printf("Resultado:%.2f", calculandoArvore(test));
    printf("\n\n");
    cortandoGalho(test);

}

