#include <iostream>
#include <string.h>

using namespace std;

typedef struct arvoreS {
	struct arvoreS *direita;
	int item;
    struct arvoreS *esquerda;
} *Arvore;

Arvore criarArvore(Arvore e, int item, Arvore d){
	Arvore novo = (Arvore)malloc(sizeof(arvoreS));
	novo->esquerda = e;
	novo->item = item;
	novo->direita = d;
	return novo;	
}

int calculate(int esq, int dir, char operation) {
    if(operation == '+') {
        return esq + dir;
    }
    if(operation == '-') {
        return esq - dir;
    }
    if(operation == '*') {
        return esq * dir;
    }
    return esq / dir;

}

int valor(Arvore arvore) {
    if(arvore->esquerda == arvore->direita) {
        return arvore->item;
    } else {
        int esq = valor(arvore->esquerda);
        int dir = valor(arvore->direita);
        return calculate(esq, dir, char(arvore->item));
    }
}


int main() {
    Arvore arvore = criarArvore(criarArvore(criarArvore(criarArvore(NULL, 5, NULL), '+', criarArvore(NULL, 3, NULL)), '/', criarArvore(NULL, 4, NULL)), '*', criarArvore(criarArvore(NULL, 6, NULL), '-', criarArvore(NULL, 1, NULL)));

    int valor1 = valor(arvore);

    cout << "Valor: " << valor1 << endl;
}