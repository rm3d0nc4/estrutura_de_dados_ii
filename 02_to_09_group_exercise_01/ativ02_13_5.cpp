#include <iostream>
#include "./arvore.hpp"

using namespace std;


int tem(Arvore arvore, int item) {
    if(arvore == NULL) return 0;
    if(arvore->item == item) return 1;
    int esq =  tem(arvore->esquerda, item);
    int dir = tem(arvore->direita , item);
    return esq + dir;
}


int main () {
    Arvore arvore = criarArvore(criarArvore(criarArvore(criarArvore(NULL, 7, NULL), 4, NULL), 2, criarArvore(NULL, 5, NULL)) , 1, criarArvore(criarArvore(NULL, 6, NULL), 3, criarArvore(NULL, 7, NULL)));

    int qtdFolhas = tem(arvore, 8);

    if(qtdFolhas) cout << "Existe"<< endl;
    else cout << "Nao existe"<< endl;
}