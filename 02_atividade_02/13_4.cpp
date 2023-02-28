#include <iostream>
#include "./arvore.hpp"

using namespace std;


int altura(Arvore arvore) {
    if(arvore == NULL) return 0;
    int esq =  altura(arvore->esquerda);
    int dir = altura(arvore->direita);
    if(esq > dir) return 1 + esq;
    return  1 + dir;
}


int main () {
    Arvore arvore = criarArvore(criarArvore(criarArvore(criarArvore(NULL, 7, NULL), 4, NULL), 2, criarArvore(NULL, 5, NULL)) , 1, criarArvore(criarArvore(NULL, 6, NULL), 3, criarArvore(NULL, 7, NULL)));

    int alturaA = altura(arvore);
    cout << "Altura: "<< alturaA << endl;
}