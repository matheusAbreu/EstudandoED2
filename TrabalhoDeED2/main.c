#include <stdio.h>
#include <stdlib.h>
#include "ArvoreDeExecucao.h"
/*
 * 
 */
int main(int argc, char** argv)
{
    tree *test;
    test = criandoRamo();
    escrevendoNULL(test);
    test->valor = 10;
    
    test->dir = criandoRamo();
    test->esq = criandoRamo();
    escrevendoNULL(test->dir);
    escrevendoNULL(test->esq);
    
    test->dir->dir = criandoRamo();
    escrevendoNULL(test->dir->dir);
    
    test->dir->valor = 50;
    test->dir->dir->valor = 50;
    
    imprimindoArvore(test, 0);
    printf("\n");
    cortandoGalho(test);
    imprimindoArvore(test, 0);
    return (EXIT_SUCCESS);
}

