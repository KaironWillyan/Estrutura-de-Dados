#include <iostream>
#include "./lista.hpp"
using namespace std;

int ehIgual(Lista lista1, Lista lista2) {
    if(lista1 == NULL && lista2 == NULL) return 1; 
    else if(lista1 != NULL && lista2 != NULL) {
        if(lista1->item == lista2->item) return ehIgual(lista1->prox, lista2->prox);
    }
    
    return 0;    
}

int main() {

    Lista lista = no(1, no(2, no(1, no(3, no(1, NULL)))));
    Lista lista2 = no(1, no(2, no(1, no(3, no(1, NULL)))));

    cout << ehIgual(lista, lista2) << endl;
}