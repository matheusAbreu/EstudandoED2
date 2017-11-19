#ifndef GRAFO_H
#define GRAFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
typedef struct _NO
{
    char info;
    struct _NO **liga;
    int *peso, qntliga;
}no;
typedef struct _GRAFO
{
    no **conteudo;
    int qnt;
} grafo;

void LimpaNo(no *x);//nao libera memoria
void LimpaGrafo(grafo *x);//nao libera memoria
void EscreveNo(no *x);
no *CriaNo();
void InserirNo(grafo *x);
void RemoverNo(grafo *x, no *y);

#ifdef __cplusplus
}
#endif

#endif /* GRAFO_H */

