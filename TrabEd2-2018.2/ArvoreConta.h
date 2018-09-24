/* 
 * File:   ArvoreConta.h
 * Author: abreu
 *
 * Created on 15 de Setembro de 2018, 10:45
 */

#ifndef ARVORECONTA_H
#define ARVORECONTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
//Definindo pro compilador: limpador de buffer e limpador de tela
#if linux
#define LIMBUF __fpurge(stdin)
#define CLS system("clear")
#endif  //linux
#if WIN32
#define LIMBUF fflush(stdin)
#define CLS system("cls")
#endif // WIN32

#ifdef __cplusplus
extern "C" {
#endif

struct MEUTEXTO typedef texto;
struct ARVORE_CONTA typedef tree;

/*Então essa estrutura foi pensada para seguir
a propia desempilhação, porém para que ela funcione precisa seguir um coerencia
de execução, que é
               Nó(Pai|Central) - será tratado como o resultado 
                                  / \
                                 /   \
  Nó(Dir) - valor em precedencia      Nó(Esq) - resultado da prox conta
                                  
Explicada a estrutura, vamos ao comportamento:
0 - A Expressão recebida TEM A OBRIGAÇÃO DE SER infixa
1 - Todo nó só poderá receber valor se não tiver não tiver filhos
2 - Todo o nó central deverá ser um sinal(por mais que em outra arvore ele venha a ser filho, se ele for o nó central em alguma arvore, ele será considerado nó central)
3 - Toda a conta considerada "precedente"(que venha a usar (); []; {}; ou simplesmente o fato de ser multiplicação ou divisao) será jogado para o ramo a direita
    3.1 - se um valor novo surgir, e o nó que o receberá não tiver filhos, nem valor, seja de expressão ou numericos, ele será considerado o ramo central de uma proxima conta
            logo, ele jogará esse novo valor pra o nó-dir e armazenará a expresão que deverá a ser executada
4 - Se uma nova expressão surgir e a arvore já esteja completa, haverá uma reorganização
    4.1 (em caso de +,- em seguida de +,-) - O ramo atua será transferido para a nó-dir(Pois a precedencia se estabelece na ordem em que aparece)
    4.2 (em caso de *,/ em seguida de +,-) - O valor do nó-esq, será jogado pra o nó-(filho)dir de si, o mesmo(Que agora passou a ser um nó-central) receberá a expressão da nova conta(*,/) e o nó-(filho)esq receberá o outro
    4.3 (em caso de +,- em seguida de *,/) ou (em caso de *,/ em seguida de *,/)-  igual ao 4.1
    4.4 (em caso de (),[],{}) - Será criado um nó-dir(que receberá (, [,{) para garantir a precedencia, e seu nó-(filho)Dir irá receber as espressões
         4.4.1 (O degrau (,[ ou {)- O ramo nulo é usado para checar se o parenteses, chaves ou colchetes fecharam, caso sim, o mesmo é removido e a conta de dentro é encaixada na expressão total, caso o contrario, um erro retorna */ 


texto *extraindoParentes(texto *expres, char abertura, int pntAbert);
texto *recebendoExpressao();
texto *criandoTexto();
tree *criandoRamo();//As arvores criadas já saem nulas
tree *escrevendoArvoreExec(texto *expres);
void anulandoRamo(tree *x);
void apagandoTexto(texto *x);
void imprimindoTexto(texto *x);
float pegandoNumeroNoTexto(texto *x, int iniPos);
void imprimindoArvore(tree *x, int nivel);
int testaGalhoInfoNula(tree *x);//Se for nulo retorna verdade 
#ifdef __cplusplus
}
#endif

#endif /* ARVORECONTA_H */

