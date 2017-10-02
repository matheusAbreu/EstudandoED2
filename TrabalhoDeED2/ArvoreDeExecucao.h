#ifndef ARVOREDEEXECUCAO_H
#define ARVOREDEEXECUCAO_H

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct ARVORE
    {
        int valor;
        char express;
        struct ARVORE *dir, *esq;
    }tree;
    
    tree *criandoRamo();
    int testaGalhoInfoNula(tree *x);
    void escrevendoNULL(tree *x);
    void cortandoGalho(tree *x);
    void imprimindoArvore(tree *x, int nivel);

#ifdef __cplusplus
}
#endif

#endif /* ARVOREDEEXECUCAO_H */

