#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

template <class T>
class No {
	public:
		T item;
		No *prox;
		No(T n){
			item = n;
			prox = NULL;
		}
};

template <class V>
class Fila{
	public:
		No<V> *inicio;
		No<V> *fim;
		
		Fila(){
			inicio = NULL;
			fim = NULL;
		}
		
		bool isEmpty() {
			return (inicio == NULL);
		}
		void append(V n){
			No<V>* no = new No<V>(n);

			if(isEmpty()) {
				inicio = no;
				fim = no;

			} else {
				fim->prox = no;
				fim = fim->prox;
			};
			// cout << fim->nome << endl;

			
		}
		
		V pop(){
			V item = inicio->item;
			inicio = inicio->prox;

			if(isEmpty()) fim = NULL;
			return item;
		}
		
	
		void popAll() {
			while(!isEmpty()) pop();
			free(&inicio);
			free(&fim);

		}

};