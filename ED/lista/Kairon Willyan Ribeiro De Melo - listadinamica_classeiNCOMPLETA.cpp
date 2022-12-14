#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class node{
	public:
		int mat;
		char nome[23];
		node *prox;
		node(int m, char n[23]){
			mat = m;
			strcpy(nome, n);
			prox = NULL;
		}
};

class Lista{
	public:
		node *inicio;
		node *fim;

		Lista(){
			inicio = NULL;
			fim = NULL;
		}

		void addToFinal(int m, char n[23]){
			node *novo = new node(m, n);
			if (fim == NULL){
				inicio = novo;
				fim = novo;
			}
			else{
				fim->prox = novo;
				fim = novo;
			}
		}

		int lst_vazia(){
			return (inicio == NULL);
		}

		void addToInicio(int m, char n[23]){
			node *newNode = new node(m,n);
			newNode->prox = inicio;
			inicio = newNode;

			if(this->lst_vazia()){
				fim = newNode;
			}
		}

		void showList()
		{
			if (lst_vazia()){
				cout << "\nLista vazia!!!";
			}
			else{
				node *aux = inicio;
				while ((aux != NULL))
				{
					cout << aux->mat << " | " << aux->nome << endl;
				}
			}
		}

		bool remove(int mat){
			if (this->lst_vazia()){
				cout << "lista vazia" << endl;
			}else{
				node *aux = inicio;
				node *anterior = NULL;

				while (aux != NULL)
				{
					if(aux->mat == mat){
						if(fim == aux){
							fim = anterior;
						}
						anterior->prox = aux->prox;
						free(aux);
						return true;
					}
					anterior = aux;
					aux = aux->prox;
				}
				cout << "elemento nao encontrado" << endl;
			}
			return false;			
		}

		// auxiliar no metodo remove, vai
		// retornar o endereco do anterior
		node *busca(int mat){
			if(this->lst_vazia()){
				cout << "Lista vazia" << endl;
			}else{
				node *aux = inicio;

				while(aux != NULL){
					if(aux->mat == mat){
						return aux;
					}
					aux = aux->prox;
				}
				cout << "Elemento nao encontrado" << endl;
			}

			return NULL;
		}

		void removeTodos(){
			node *atual = inicio;
			node *proximo = NULL;
			while (atual != NULL)
			{
				proximo = atual->prox;
				cout << "\n Apaga:" << atual->nome;
				free(atual);
				atual = proximo;
			}
			inicio = atual;
		}

		// criar uma nova lista que seja o inverso da primeira
		Lista *crialistainversa(){
			if(this->lst_vazia()){
				cout << "Lista vazia" << endl;
			}else{
				Lista *novaList = new Lista();
				node *atual = inicio;
				node *prox = inicio->prox;
				novaList->addToInicio(inicio->mat, inicio->nome);

				while(atual->prox != NULL){
					atual = prox;
					prox = atual->prox;
					novaList->addToInicio(inicio->mat, inicio->nome);
				}

				return novaList;
			}
		}

		// inverter a propria lista
		void listainvertida(){
			if(this->lst_vazia()){
				cout << "Lista vazia" << endl;
			}else{
				node *atual = inicio;
				node *prox = atual->prox;
				node *anterior = NULL;
				atual->prox = NULL;
				fim = inicio;

				while(prox != NULL){
					anterior = atual;
					atual = prox;
					prox = atual->prox;

					atual->prox = anterior;

					if(prox == NULL){
						inicio = atual;
					}
				}
			}
		}
};
main(){
	Lista *l = new Lista();
	l->addToFinal(1, "Joao");
	l->addToFinal(2, "Gabriela");
	l->addToFinal(3, "Fabiola");
	l->addToInicio(5, "Joana Oliveira");
	l->addToInicio(6, "Cristiano Oliveira");
	l->showList();

	l->listainvertida();
	l->showList();
}

/*
Fa??a usando o modelo da op????o 2 (usando classes):
1. Escreve o m??todo para inserir no inicio e no final da lista.
2. Escreva o m??todo consultar, aonde ser?? pesquisado um aluno atrav??s do n??mero de
matr??cula. Se o aluno for encontrado uma mensagem com matr??cula e nome deve ser
impressa na tela do computador, se o aluno n??o for encontrado, a mensagem deve
informar que o aluno n??o existe.
3. Escreva o m??todo remover, aonde ser?? retirado um elemento da lista.
4. Escreva o m??todo listar, aonde ser??o listados todos os elementos da lista.
5. Criar uma nova lista que seja o inverso da primeira j?? criada.
6. Inverter a pr??pria lista.
*/