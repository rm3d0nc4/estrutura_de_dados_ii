#include <iostream>
#include "../02_atividade_02/arvore.hpp"

using namespace std;

int eb(Arvore arvore) {
    if(arvore == NULL) return 0;
    int esq = eb(arvore->esquerda);
    int dir = eb(arvore->direita);
    if(esq == dir) return 1;
    return 0;
}

int main () {
    Arvore arvore = criarArvore(criarArvore(NULL, 5, NULL), 5, criarArvore(NULL, 5, NULL));
    int exclusivamenteBinaria = eb(arvore);
    
    if(exclusivamenteBinaria) {
        cout << "Exclusivamente binária!" << endl;
    } else {
        cout << " Não exclusivamente binária!" << endl;
    }
}