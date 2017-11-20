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
grafo *CriaGrafo();
void InserirNo(grafo *x);
void RemoverNo(grafo *x, int posY);//Nao funciona
void RemoverCaminho(grafo *x, int posY, int posZ);//Y é onde apagara, e Z é o no destino no qual deseja-se que se apague o caminho
void ApagarGrafo(grafo *x);
void InserirCaminhoDuplo(grafo *x, int posY, int posZ, int peso);//Insere o caminho entre os dois nós, ido e voltando
void InserirCaminho(grafo *x, int posY, int posZ, int peso);//Insere o caminho do nó, posY para posZ
void ImprimindoNo(no *x);
void ImprimindoMatrizDoGrafo(grafo *x);

#ifdef __cplusplus
}
#endif

#endif /* GRAFO_H */

