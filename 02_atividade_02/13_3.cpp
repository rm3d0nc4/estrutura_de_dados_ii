#include <iostream>
#include "./arvore.hpp"

using namespace std;


int folhas(Arvore arvore) {
    if(arvore->direita == NULL && arvore->esquerda == NULL) return 1;
    int esq =  folhas(arvore->esquerda);
    int dir = folhas(arvore->direita);
    return esq + dir;
}


int main () {
    Arvore arvore = criarArvore(criarArvore(criarArvore(NULL, 4, NULL), 2, criarArvore(NULL, 5, NULL)) , 1, criarArvore(criarArvore(NULL, 6, NULL), 3, criarArvore(NULL, 7, NULL)));

    int qtdFolhas = folhas(arvore);
    cout << "Folhas: "<< qtdFolhas << endl;
}