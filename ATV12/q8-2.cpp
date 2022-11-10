#include <iostream>
#include <cstring>
using namespace std;

void print(char lista[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        cout << lista[i] << " ";
    }
}

void insere(char elemento, char vetor[], int posicao) {
    while (posicao > 0 && elemento < vetor[posicao-1]) {
        vetor[posicao] = vetor[posicao-1];
        posicao--;
    }
    vetor[posicao] = elemento;
}

void insertionSort(char vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        insere(vetor[i], vetor, i);
    }
}

int main() {
    const int tamanho = 8;
    char lista[] = "Kairon";

    insertionSort(lista, tamanho);
    print(lista, tamanho);
}