#include <iostream>
#include "../02_atividade_02/arvore.hpp"

using namespace std;

int igual(Arvore A, Arvore B) {
    if(A == B) return 1; // Validar se os nós são nulos
    if(A != B && (A == NULL || B == NULL)) return 0; // Validar se pelo menos um dos nós é nulo

    if(A->item != B->item) return 0; // Verificar se os valores dos itens são diferentes
    int esq = igual(A->esquerda, B->esquerda); // Verificar igualdade das esquerdas
    int dir = igual(A->direita, B->direita); // Verificar igualdade das direitas
    if(esq + dir == 2) return 1; //Validar igualdades
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