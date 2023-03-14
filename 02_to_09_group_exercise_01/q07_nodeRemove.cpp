#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
} Arv;


Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;	
}

void imprime(Arv *n){		
					
			if (n!=NULL){
					
				cout<<"<"<<n->info;
				imprime(n->esq);
				imprime(n->dir);
				cout<<">";
			   }
			   else
			     cout<<"<>";
			}

// remove o nó procurado. Se o nó tiver filhos, remova também os filhos	


void printTreeFormated(Arv *root){
    if(root != NULL){
        cout << "<" << root->info;

        printTreeFormated(root->esq);
        printTreeFormated(root->dir);
        cout << ">";
    }
}

void desalocaNo(Arv *no) {
	if(no == NULL) return;

	desalocaNo(no->dir);
	desalocaNo(no->esq);

	free(no);
	no = NULL;
}

int removeSubArvore(Arv **no, char valor){
	if(*no == NULL) return 0;

	if((*no)->info == valor) {
		desalocaNo(*no);
		*no = NULL;
		return 1;
	}

	if((*no)->dir != NULL && (*no)->dir->info == valor) {
		desalocaNo((*no)->dir);
		(*no)->dir = NULL;
		return 1;
	}

	if((*no)->esq != NULL && (*no)->esq->info == valor) {
		desalocaNo((*no)->esq);
		(*no)->esq = NULL;
		return 1;
	}


	return removeSubArvore(&((*no)->esq), valor) + removeSubArvore(&((*no)->dir), valor);
}

    
int main(){
 
 Arv *tree1 = arvore(
				'1',
				arvore(
					'2', 
					arvore('4', NULL, NULL), 
					arvore('5', NULL, NULL)
					),
				arvore(
					'3', 
					NULL,
					arvore('6', NULL, NULL) 
					)
				);
 
	printTreeFormated(tree1);
	cout << endl;

	removeSubArvore(&tree1, '3');

	printTreeFormated(tree1);
	cout << endl;

	removeSubArvore(&tree1, '4');

	printTreeFormated(tree1);
	cout << endl;


	removeSubArvore(&tree1, '5');

	printTreeFormated(tree1);
	cout << endl;

	
	removeSubArvore(&tree1, '1');

	printTreeFormated(tree1);
	cout << endl;

return 1;
 
}