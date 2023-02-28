#include <iostream>
#include "./arvore.hpp"

using namespace std;

int nos(Arvore arvore) {
    if(arvore == NULL) return 0;
    int esq =  nos(arvore->esquerda);
    int dir = nos(arvore->direita);
    return esq + 1 + dir;
}



int main () {
    Arvore arvore = criarArvore(criarArvore(criarArvore(NULL, 4, NULL), 2, criarArvore(NULL, 5, NULL)) , 1, criarArvore(criarArvore(NULL, 6, NULL), 3, criarArvore(NULL, 7, NULL)));

    int qtdNos = nos(arvore);
    cout << "Nos: " <<qtdNos << endl;
}