#include "Pilha.hpp"
#include "Fila.hpp"
#include <iostream>
#include <string>

int main() {
    string sentenca;
    getline(cin, sentenca);

    Fila<char>* fila= new Fila<char>();
    Pilha<char> pilha(sentenca.length());


    for(int i = 0; i < sentenca.length(); i++) {
        if(isalpha(sentenca[i])) {
            fila->append(sentenca[i]);
            pilha.push(sentenca[i]);
        }
    }

    while (!fila->isEmpty() && toupper(fila->pop()) == toupper(pilha.pop())) {}

    if(fila->isEmpty()) {
        cout << "Sentenca palindroma!" << endl;
    } else {
        cout << "Sentenca nao palindroma!" << endl;
    }

    
}