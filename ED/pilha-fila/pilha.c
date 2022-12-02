#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No{
	public:
		char nome;
		No* prox;
		No(char n){
			nome = n;
			prox = NULL;
		}
};

class Pilha{
	public:
		No* topo = NULL;

		void push(char n){
			No* no = new No(n);
			no->prox = topo;
			topo = no;
		}
		
		char pop(){
			if(!isEmpty()) {
				char item = topo->nome;
				topo = topo->prox;
				return item;
			}
		}
		
		bool isEmpty(){
			return topo == NULL;
		}
	
	
};

int main() {
	Pilha pilha;
	pilha.push('o');
	pilha.push('r');
	pilha.push('e');
	cout << pilha.pop() << endl;
	cout << pilha.pop() << endl;
	cout << pilha.pop() << endl;

	
}