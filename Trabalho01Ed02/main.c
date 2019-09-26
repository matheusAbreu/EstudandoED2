#include <stdio.h>
#include <stdlib.h>
#include "Ordenadores.h"
void main()
{
    item *teste;
    teste = CriandoListaRand(30, 100);

    ImprimindoListaItem(teste);

    ApagandoLista(teste);

    ImprimindoListaItem(teste);
}
