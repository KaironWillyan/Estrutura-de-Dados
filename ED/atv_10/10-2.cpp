#include <iostream>
#include "./atv_10/listaOrdenada.hpp"

int main() {
    Lista lista1 = nullptr;
    int insere = -1;
    int valor;

    while(true) {
        cout << "Inserir Valor (1 - sim, 0 - nao): ";
        cin >> insere;

        if(insere == 1) {
            cout << "Valor: ";  
            cin >> valor;
            if(lista1 == NULL) lista1 = no(valor, NULL);
            else inserir(valor, &lista1);
        } else if(insere == 0) {
            cout << "Lista Invertida:" << endl;
            exibirInvertido(lista1);
            break;
        } else {
            cout << "Valor invalido. Tente Novamente!" << endl;
        }

    }
}