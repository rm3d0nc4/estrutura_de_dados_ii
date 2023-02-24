#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	struct arv *dir;
	int info;
    struct arv *esq;
} *Arv;

Arv arvore(Arv e, int info, Arv d){
	Arv novo = (Arv)malloc(sizeof(Arv));
	novo->esq = e;
	novo->info = info;
	novo->dir = d;
	return novo;	
}

Arv criarVazia() {
	return NULL;
}


int isEmpty(Arv a) {
	if(a == NULL) return 1;
	return 0;
}

void percorrer(Arv a) {
	if(!isEmpty(a)) {
		cout << "<" << a->info;
		printf("<%i", a->info);
		percorrer(a->dir);
		percorrer(a->esq);
	} else {
		printf(">");
	}
}

int main(){

	Arv arvore1 = arvore(arvore(criarVazia(), 2, criarVazia()), 1, arvore(criarVazia(), 3, criarVazia()));
	percorrer(arvore1);
	return 0;
}
