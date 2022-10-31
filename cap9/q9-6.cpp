#include <iostream>
#include "./lista.hpp"
using namespace std;

void substitui(Item item, Item substituto, Lista lista) {
    if(lista == NULL) return;
    
    if(lista->item == item) lista->item = substituto;
    return substitui(item, substituto, lista->prox);
}

int main() {

    Lista lista = no(1, no(2, no(1, no(3, no(1, NULL)))));
    substitui(1, 4, lista);

    exibir(lista);
}