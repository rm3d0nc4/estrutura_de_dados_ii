#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include"ctype.h"

struct NoArv
{
    int info;
    struct NoArv *esquerda;
    struct NoArv *direita;
};

NoArv *criarArvoreVazia()
{
    return NULL;
}

NoArv *criarArvore(int info, NoArv *Lson, NoArv *Rson)
{
    NoArv *son = (NoArv *)malloc(sizeof(NoArv));
    son->info = info;
    son->esquerda = Lson;
    son->direita = Rson;
    return son;
}

bool is_null(struct NoArv *node)
{
    if (node == NULL)
    {
        return true;
    }
    return false;
}

int exibir_arvore_decrescente(NoArv* raiz) {
    if (is_null(raiz)) {
        return 0;
    }
    exibir_arvore_decrescente(raiz->direita);
    printf("%i \n", raiz->info);
    exibir_arvore_decrescente(raiz->esquerda);
}

int main() {
    NoArv* raiz = 
    criarArvore(
        50, 
        criarArvore
        (
            30, 
            criarArvore
            (
                20, NULL, NULL
            ), 
            criarArvore
            (
                40, 
                criarArvore(
                    35, NULL, criarArvore(37, NULL, NULL)
                ),
                criarArvore(
                    45, NULL, NULL
                )
            )
        ), 
        criarArvore
        (
            100, NULL, NULL
        )
    );

    exibir_arvore_decrescente(raiz);
}