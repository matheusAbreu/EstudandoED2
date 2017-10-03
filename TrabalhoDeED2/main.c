#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreDeExecucao.h"
#define MAX 50
//Definindo pro compilador: limpador de buffer e limpador de tela
#if linux
#define LIMBUF __fpurge(stdin)
#define CLEARSCREEN system("clear")
#endif  //linux
#if WIN32
#define LIMBUF fflush(stdin)
#define CLEARSCREEN system("cls")
#endif // WIN32
/*
 * 
 */
int main(int argc, char** argv)
{
   // y = atoi(testando);
    int i;
    char express[MAX];
    tree *test;
    test = criandoRamo();
    
    scanf("%s", express);
    LIMBUF;
    
    printf("\n%s\n", express);
    i = strlen(express);
    
    escrevendoExpresao(test, express,i);
    imprimindoArvore(test,0);
    cortandoGalho(test);
    
    return (EXIT_SUCCESS);
}

