#include "grafo.h"
void main() 
{
    grafo *x;
    
    
    x = CriaGrafo();
   
    InserirNo(x);
    InserirNo(x);
    InserirNo(x);
    InserirNo(x);
    InserirNo(x); 
    x->conteudo[0]->info = 'a';
    x->conteudo[1]->info = 'b';
    x->conteudo[2]->info = 'c';
    x->conteudo[3]->info = 'd';
    x->conteudo[4]->info = 'e';
    InserirCaminho(x,0,1, 10);
    InserirCaminho(x,0,2, 50);
    InserirCaminho(x,0,3, 65);
    InserirCaminho(x,1,2, 30);
    InserirCaminho(x,1,4, 4);
    InserirCaminho(x,2,3, 20);
    InserirCaminho(x,2,4, 44);
    InserirCaminho(x,3,1, 70);
    InserirCaminho(x,3,4, 23);
    InserirCaminho(x,4,0, 6);
    ImprimindoMatrizDoGrafo(x);
    //RemoverNo(x, 1);
    ImprimindoMatrizDoGrafo(x);
    ApagarGrafo(x);
}

