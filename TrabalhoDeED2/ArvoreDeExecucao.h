#ifndef ARVOREDEEXECUCAO_H
#define ARVOREDEEXECUCAO_H

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct ARVORE
    {
        float valor;
        char express;
        struct ARVORE *dir, *esq;
    }tree;
    
    tree *criandoRamo();
    int testaGalhoInfoNula(tree *x);
    void escrevendoNULL(tree *x);
    void cortandoGalho(tree *x);
    void imprimindoArvore(tree *x, int nivel);
    void escrevendoExpresao(tree *x, char *ex, int tam);
    int testaNumero(char x);//retorna 1 se for numero e 0 caso nao
    void imprimindoEmPosFixa(tree *x);
    float calculandoArvore(tree *x);
    
#ifdef __cplusplus
}
#endif

#endif /* ARVOREDEEXECUCAO_H */

