/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   procurando.h
 * Author: matheus
 *
 * Created on 23 de Setembro de 2017, 17:39
 */

#ifndef PROCURANDO_H
#define PROCURANDO_H

#ifdef __cplusplus
extern "C" {
#endif

void procurandoMaioMenor(int *vet, int *men, int *mai, int tam);//Retorna o menor e o maior valores encontrados respectivamente nas variaves "men" e "mai"
int procurandoChave(int *x, int tam);//retorna o valor da posicao onde se encontra a primeira "chave", retorna -1 se não encontrar
int procurandoOMaior(int *x, int tam);//retorna o maior valor encontrado
int procurandoOMenor(int *x, int tam);//retorna o menor valor encontrado
void procurandoMaiorPosi(int *x, int *pos, int *maior,int tam);//retorna a posição e o valor dele no vetor passado, respetivamente através das variaveis pos e maior
void procurandoMenorPosi(int *x, int *pos, int *menor,int tam);//retorna a posição e o valor dele no vetor passado, respetivamente através das variaveis pos e menor

#ifdef __cplusplus
}
#endif

#endif /* PROCURANDO_H */

