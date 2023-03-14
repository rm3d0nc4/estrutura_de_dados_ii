#include <iostream>
#include "../02_atividade_02/arvore.hpp"

using namespace std;

void exibe_dec(Arvore arvore) {
    if(arvore == NULL) return;
    exibe_dec(arvore->direita);
    cout << arvore->item << endl;
    exibe_dec(arvore->esquerda);
}


int main() {
    Arvore arvore = criarArvore(criarArvore(criarArvore(criarArvore(NULL, 0, NULL), 1, criarArvore(NULL, 2, NULL)), 3, criarArvore(NULL, 4, NULL)), 5, criarArvore(criarArvore(NULL, 6, NULL), 7, criarArvore(criarArvore(NULL, 8, NULL), 9, NULL)));

    exibe_dec(arvore);
}