#include <iostream>
#include "./polinomio.hpp"

void somarPolinomios(Poli *polinomio1, Poli polinomio2) {
    if(polinomio2 == NULL) return;
    addTermo(polinomio2->coeficiente, polinomio2->expoente, polinomio1);
    somarPolinomios(polinomio1, polinomio2->prox);
}

int main() {
    Poli polinomio1 = termo(2, 4, termo(3, 3, termo(6, 2, NULL)));
    Poli polinomio2 = termo(7, 5, termo(4, 4, termo(2, 3, termo(3, 2, NULL))));
    somarPolinomios(&polinomio1, polinomio2);

    exibirPolinomio(polinomio1);
}