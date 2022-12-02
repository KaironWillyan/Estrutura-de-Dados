#include <iostream>
#include "./lista_ordenada.hpp"

void insSR(Item item, Lista *lista) {
    if(estaEm(item, *lista)) cout << "Elemento ja esta na lista" << endl;
    else inserir(item, lista);
}

int main() {

    Lista lista = no(3, no(4, no(5, no(6, NULL))));
    insSR(1, &lista);
    insSR(1, &lista);
    insSR(2, &lista);
    insSR(7, &lista);
    exibir(lista);
}