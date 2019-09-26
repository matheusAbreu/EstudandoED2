#ifndef ORDENADORES_H_INCLUDED
#define ORDENADORES_H_INCLUDED

#if linux
#define LIMP __fpurge(stdin)
#define CLS system("clear")
#endif
#if WIN32
#define LIMP fflush(stdin)
#define CLS system("cls")
#endif

struct ITEM
{
    int valor;
    struct ITEM *prox;

}typedef item;

item *CriandoItem();
void ApagandoItem(item *x);
void ApagandoLista(item *x);
item *CriandoListaRand(int qntitens, int randMax);
void ImprimindoListaItem(item *x);

#endif // ORDENADORES_H_INCLUDED
