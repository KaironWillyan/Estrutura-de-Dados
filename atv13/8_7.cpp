#include <iostream>
using namespace std;

//Atividade em dupla feita por Kairon Willyan e Maria Vitória

bool binarySearch(int x, int v[], int n, int u){
    int m = (u+n)/2;

    if(x == v[m]){
        return true;
    }

    if(x < v[m]) {
        n = m-1;
    } else {
        u = m+1;
    }

    if(n < u){
        return false;
    }

    return binarySearch(x, v, n, u);     
}

int main(){
    int v[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11};
    
        if(binarySearch(6, v, 10, 0)){
            cout << "item encontrado" << endl;
        } else {
            cout << "item nao encontrado" << endl;
        } 
}
