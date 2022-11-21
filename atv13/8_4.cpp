#include <iostream>
using namespace std;

#define troca(a, b) {int x = a; a = b; b = x; }

int seleciona(int v[], int n) {
    int i = 0;
    for(int j = 1; j < n; j++){
        if(v[i] < v[j]) {
            i = j;
        }
    }
    return i;
}

void selectionSort(int v[], int n){
    if(n == 0) return;
    troca(v[seleciona(v, n)], v[n-1]);
    n--;
    selectionSort(v, n);
}

int main(){
    int v[] = {3, 2, 66, 8, -12, 9, 32, -5};
    selectionSort(v, 8);

    for (int i = 0; i < 8; i++) {
        cout << v[i] << " ";
    }
}