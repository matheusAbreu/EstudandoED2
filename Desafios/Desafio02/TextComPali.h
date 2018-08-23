/* 
 * File:   TextComPali.h
 * Author: abreu
 *
 * Created on 21 de Agosto de 2018, 21:14
 */

#ifndef TEXTCOMPALI_H
#define TEXTCOMPALI_H

#if linux
#define LIMP __fpurge(stdin)
#endif
#if WIN32
#define LIMP fflush(stdin)
#endif

struct MEUTEXTO
{
    int tam, qntEsp, *posEsp;
    char *vetor;
    
}typedef MeuTexto;

//struct MEUTEXTO typedef MeuTexto;
void limpandoMeuTexto(MeuTexto *x);
MeuTexto *criandoMeuTexto();
void identificandoEspacos(MeuTexto *x);
void copiandoMeuTexto(MeuTexto *dest, MeuTexto *ori, int ini, int fim);
void imprimindoMeuTexto(MeuTexto *x);
void escrevendoMeuTexto(MeuTexto *x);
int verificandoPalindromo(MeuTexto *y, int ini, int fim);
MeuTexto *procurandoMaiorPalindro(MeuTexto *x);

#endif /* TEXTCOMPALI_H */

