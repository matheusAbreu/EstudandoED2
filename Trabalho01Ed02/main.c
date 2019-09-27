#include <stdio.h>
#include <stdlib.h>
#include "Ordenadores.h"
void main()
{
    item *teste;
    teste = CriandoListaRand(10000, 100);

    ImprimindoListaItem(teste);

    teste = ApagandoLista(teste);

    ImprimindoListaItem(teste);
}
