#include <iostream>
#define troca(a, b) {int x = a; a = b; b = x; }

using namespace std;

void empurra(int vetor[], int n) {
    for(int i = 0; i < n; i++) {
            if(vetor[i] > vetor[i+1]) {
                troca(vetor[i], vetor[i+1]);
            }
    } 
}

void bubbleSort(int vetor[], int n) {
    if(n == 0) return;
    else {
        empurra(vetor, n);
        bubbleSort(vetor, n-1);
    }
}

int main() {
    int numeros[] = {3,5,6,2,9,7,1,8,4};
    bubbleSort(numeros, 9);
    int tamanho = sizeof(numeros) / sizeof(int);
    for(int i = 0; i < 9; i++) {
        cout << numeros[i] << endl;
    }
}