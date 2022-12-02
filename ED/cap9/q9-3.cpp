#include <iostream>
#include "./lista.hpp"
using namespace std;

Item ultimo(Lista lista) {
    if(lista == NULL) return -1;
    while (lista->prox != NULL) lista = lista->prox;
    return lista->item;
}

int main() {
    Lista lista = no(1, no(2, no(3, no(4, no(5, NULL)))));
    Lista lista2 = no(1, no(2, no(3, no(4, NULL))));
    Lista lista3 = no(1, NULL);

    cout << ultimo(lista) << endl;
    cout << ultimo(lista2) << endl;
    cout << ultimo(lista3) << endl;
}