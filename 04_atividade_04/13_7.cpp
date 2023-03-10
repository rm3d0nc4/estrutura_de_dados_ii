#include <iostream>
#include "../02_atividade_02/arvore.hpp"

using namespace std;

int igual(Arvore A, Arvore B) {
    if(A == B) return 1;
    if(A != B && (A == NULL || B == NULL)) return 0;

    if(A->item != B->item) return 0;
    int esq = igual(A->esquerda, B->esquerda);
    int dir = igual(A->direita, B->direita);
    if(esq + dir == 2) return 1;
    return 0;

}

int main() {
    Arvore arvore1 = criarArvore(criarArvore(NULL, 5, NULL), 5, criarArvore(NULL, 5, NULL));
    Arvore arvore2 = criarArvore(criarArvore(NULL, 5, NULL), 5, criarArvore(NULL, 5, NULL));
    int arvoresIguais = igual(arvore1, arvore2);

    if(arvoresIguais) {
        cout << "Arvores iguais" << endl;
    } else {
        cout << "Arvores diferentes" << endl;
    }
}