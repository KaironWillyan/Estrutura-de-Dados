#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No{
	public:
		char nome;
		No *prox;
		No(char n){
			nome = n;
			prox = NULL;
		}
};

class Fila{
	public:
		No *inicio;
		No *fim;
		
		Fila(){
			inicio = NULL;
			fim = NULL;
		}
		
		void append(char n){
			No* no = new No(n);

			if(isEmpty()) {
				inicio = no;
				fim = no;

			} else {
				fim->prox = no;
				fim = fim->prox;
			};
			// cout << fim->nome << endl;

			
		}
		
		char pop(){
			char item = inicio->nome;
			inicio = inicio->prox;

			if(isEmpty()) fim = NULL;
			return item;
		}
		
		bool isEmpty() {
			return (inicio == NULL);
		}
	
		void popAll() {
			while(!isEmpty()) pop();
			free(&inicio);
			free(&fim);

		}

};

int main(){ 
	Fila* fila = new Fila();

	fila->append('r');
	fila->append('o');
	fila->append('m');
	fila->append('e');
	fila->append('r');
	fila->append('o');

	while(!(fila->isEmpty())) cout  << fila->pop() << endl;
}