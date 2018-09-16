#include "ArvoreConta.h"

struct ARVORE_CONTA
{
    float valor;
    char express;
    struct ARVORE_CONTA *dir, *esq;
}typedef tree;

struct MEUTEXTO
{
    char *valor;
    int tam;
}typedef texto;

tree *criandoRamo()
{
    tree *x;
    x = (tree*)malloc(1*sizeof(tree));
    if(x != NULL)
    {
         anulandoRamo(x);
        return x;
    }
    else
        printf("\nHouve um erro na alocacao - Funcao:CriandoRamo\n");
}

texto *criandoTexto()
{
    texto *x;
    x = (texto*)malloc(1*sizeof(texto));
    if(x != NULL)
        return x;
    else
        printf("\nHouve um erro na alocacao - Funcao:CriandoRamo\n");
}

texto *recebendoExpressao()
{
    int tam;
    char temp[1000], *expres;
    texto *y;
    y = criandoTexto();
    
    gets(temp);
    LIMBUF;
    
    tam = strlen(temp);
    if(tam > 2)
    {
        expres = NULL;
        expres = (char*)malloc((tam+1)*sizeof(char));
        
        if(expres != NULL)
        {
            strcpy(expres, temp);
            y->tam = tam;
            y->valor=expres;
            return y;
        }
        else
            printf("\nHouve um erro na alocacao - Funcao:recebendoExpressao\n");
    }
    else
            printf("\nHouve um erro na alocacao - Funcao:recebendoExpressao\n");

}
void anulandoRamo(tree *x)
{
    x->valor = 0.0f;
    x->express = NULL;
    x->dir = NULL;
    x->esq = NULL;
}
void apagandoTexto(texto *x)
{
    free(x->valor);
    x->valor = NULL;
    x->tam = 0;
}
int verificandoNumero(char y)
{
    if(y=='0'|| y=='1'|| y=='2'|| y=='3'|| y=='4'|| y=='5'|| y=='6'|| y=='7'|| y=='8'|| y=='9'|| y=='.')
        return 1;
    else
        return 0;
}
float pegandoNumeroNoTexto(texto *x, int iniPos)
{
    int i,j;
    char *temp;
    for(i = iniPos; i < x->tam;i++)
    {
        if(!verificandoNumero(x->valor[i]))
            break;
    }
    temp = (char *)malloc(((i-iniPos)+1)*sizeof(char));
    if(temp == NULL)
    {
        printf("\nHouve um erro na alocacao - Funcao:pegandoNumeroNoTexto\n");
        return 0.0;
    }
    else
        for(j=iniPos; j<i;j++)
            temp[j] = x->valor[iniPos+j];
    
    temp[(i-iniPos)+1] = '\0';
    
    
    return atof(temp);
}
void imprimindoTexto(texto *x){printf("%s", x->valor);}
tree *EscrevendoArvoreExec(texto *expres)
/*1 -  se a expressao tiver valor
  0 - caso não*/
{
    int i, iniPos = 0;
    char ultEsp = NULL;
    float valor = 0.0;
    tree *x, *noCab, *temp;
    noCab = x = criandoRamo();
    
        for(i=1; i < expres->tam;i++)
        {
            switch(expres->valor[i])
            {
                //as contas
                case '+':
                case '-':
                    
                    if(x->express == NULL && x->dir == NULL)
                    {
                        x->dir = criandoRamo();
                        x->dir->valor = pegandoNumeroNoTexto(expres, iniPos);
                        x->express = expres->valor[i];
                    }
                    //testando se a ultima expressao usada é da mesma precedencia
                    else if('-' == ultEsp ||'+' == ultEsp )
                    {
                        x->esq = criandoRamo();
                        x->esq->valor = pegandoNumeroNoTexto(expres, iniPos);
                        temp = criandoRamo();
                        temp->dir = x;
                    }
                   iniPos = i+1; 
                break;
                case '*':
                    break;
                case '/':
                    break;
                    
                //A "abertura dos parenteses"    
                case '(':
                    break;
                case '[':
                    break;
                case '{':
                    break;
                    
                //O Fechamento dos "parenteses"
                case ')':
                    break;
                case '}':
                    break;
                case ']':
                    break;
                    
            }
        }
    if(iniPos < i)
    {
        x->valor = pegandoNumeroNoTexto(expres, iniPos);
    }
    
}
void imprimindoArvore(tree *x, int nivel)
{
    char aux[50];
    int i;
    
    for(i = 0; i < nivel; i++)
        aux[i]='\t';
    
    aux[nivel] = '\0';
    
    if(testaGalhoInfoNula(x))
        printf("\n%sNULL", aux);
    else if(x->valor != 0.0f)
        printf("\n%s%.2f",aux, x->valor);
    else
        printf("\n%s%c", aux, x->express);
    
    if(x->esq != NULL)
        imprimindoArvore(x->esq, (nivel +1));
    
    if(x->dir != NULL)
        imprimindoArvore(x->dir, (nivel +1));
}
int testaGalhoInfoNula(tree *x)
{
    if(x->express == NULL && x->valor == 0.0f)
        return 1;
    else
        return 0;
}