#include <iostream>
using namespace std;

void insere(int x, int v[], int n) {
    while(n > 0 && x < v[n-1]) {
        v[n] = v[n-1];
        n--;
    }
    v[n] = x;
}

void insertionSort(int *v, int n){
    if(n == 1) {
        return;
    } 
    n--;
    insertionSort(v, n);
    insere(v[n], v, n);
}

int main(){
    int v[] = {3, 2, 66, 8, -12, 9, 32, -5};

    insertionSort(v, 8);

    for (int i = 0; i < 8; i++) {
        cout << v[i] << " ";
    }
}