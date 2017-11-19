#include "grafo.h";

void LimpaNo(no *x)
{
    x->info = NULL;
    x->liga = NULL;
    x->peso = NULL;
    x->qntliga = NULL;
    
}
void LimpaGrafo(grafo *x)
{
    x->conteudo = NULL;
    x->qnt = NULL;
}
void EscreveNo(no *x)
{
    /*tem que estruturar
     *leitura de arquivo pra depois bolar a escrita do nó cuzão*/
}
no *CriaNo()
{
    no *x;
    x = (no*)malloc(1*sizeof(no));
    if(x == NULL)
    {
        printf("\ndeu ruim...\n");
        return NULL;
    }
    else
    {
        LimpaNo(x);
        return x;
    }
}
void InserirNo(grafo *x)
{
    no *novo;
    novo = CriaNo();
    LimpaNo(novo);
    //EscreveNo(novo);
    
    if(x->conteudo == NULL)
    {
        x->conteudo = (no**)malloc(1*sizeof(no*));
        if(x->conteudo == NULL)
            printf("\nDeu ruim\n");
        else
            x->conteudo[0] = novo;
    }
    else
    {
        x->conteudo = (no**)realloc((x->qnt+1)*sizeof(no*));
        if(x->conteudo == NULL)
            printf("\nDeu ruim\n");
        else
        {
            x->conteudo[x->qnt] = novo;
            x->qnt++;
        }
    }
}
void RemoverNo(grafo *x, no *y)
{
    int i, j, oni = 0, onj = 0;
    /*oni e onj são gatilhos(on de i, on de j)
     * onde estiver com o valor zero estaram desligados(off)
     * se estiverem 1 estaram ligados(on)
     * i e j são os sufixos que indicam em qual dos laços(a seguir) as variaveis estão atuando
     */
    
    for(i =0;i<x->qnt;i++)
    {
        if(x->conteudo[i] == y)
            oni = 1;
        if(oni != 0)
            x->conteudo[i] = x->conteudo[i+1];
        for(j = 0; j<x->conteudo->qntliga; j++)
        {
            if(x->conteudo[i]->liga[j]==y)
                onj = 1;
            if(onj != 0)
            {
                x->conteudo[i]->liga[j] = x->conteudo[i]->liga[j+1];
                x->conteudo[i]->liga[j] = x->conteudo[i]->peso[j+1];
                x->conteudo[i]->liga[j] = x->conteudo[i]->qntliga[j+1];
                x->conteudo[i]->liga[j] = x->conteudo[i]->info[j+1];
            }
        }
        if(onj != 0)
        {
            x->conteudo[i]->qntliga --;
            x->conteudo[i]->liga = (no**)realloc((x->conteudo[i]->qntliga)*sizeof(no*));
            x->conteudo[i]->peso = (int*)realloc((x->conteudo[i]->qntliga)*sizeof(int));
            onj =0;
        }
    }
    if(oni != 0)
    {
        x->qnt --;
        x->conteudo=(no**)realloc((x->qnt)*sizeof(no*));
    }
}
void ApagarGrafo(grafo *x)
{
    int i,j;
    for(i =0; i < x->qnt; i++)
    {
        for(j = 0; j < x->conteudo[i]->qntliga;j++)
            free((x->conteudo[i]->liga[j]));
        
        free((x->conteudo[i]->peso));
        free((x->conteudo[i]->liga));
        free((x->conteudo[i]));
    }
    free(x->conteudo);
    LimpaGrafo(x);
}
void InserirCaminho(grafo *x, int posY, int posZ, int peso)
{
    if(posY < x->qnt && posZ < x->qnt)
    {
        x->conteudo[posY]->liga = (no**) realloc((x->conteudo[posY]->qntliga+1)*sizeof(no*));
        x->conteudo[posY]->peso = (int*) realloc((x->conteudo[posY]->qntliga+1)*sizeof(int));
        x->conteudo[posY]->liga[x->conteudo[posY]->qntliga] = x->conteudo[posZ];
        x->conteudo[posY]->peso[x->conteudo[posY]->qntliga] = peso;
        x->conteudo[posY]->qntliga++;
        
        x->conteudo[posZ]->liga = (no**) realloc((x->conteudo[posZ]->qntliga+1)*sizeof(no*));
        x->conteudo[posZ]->peso = (int*) realloc((x->conteudo[posZ]->qntliga+1)*sizeof(int));
        x->conteudo[posZ]->liga[x->conteudo[posZ]->qntliga] = x->conteudo[posZ];
        x->conteudo[posZ]->peso[x->conteudo[posZ]->qntliga] = peso;
        x->conteudo[posZ]->qntliga++;
    }
    else
        printf("\nUm dos nos nao foi encontrado\n");
}
void ImprimindoNo(no *x)
{
    int i;
    printf("|no:%c|:", x->info);
    for(i =0; i< x->qntliga; i++)
        printf("->|i:%c|p:%d|", x->liga[i], x->peso[i]);
}
void ImprimindoMatrizDoGrafo(grafo *x)
{
    int i;
    printf("\nGrafo:");
    for(i =0; i<x->qnt;i++)
    {
        printf("\n%d:", i);
        ImprimindoNo(x->conteudo[i]);
    }
}