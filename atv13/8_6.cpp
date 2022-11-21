#include <iostream>
using namespace std;

bool linearSearch(int x, int v[], int n){
    if(x == v[n]){
        return true;
    }
    n--;

    if(n == 0){
        return false;
    }

    return linearSearch(x, v, n);     
}


int main(){
    int v[] = {3, 2, 66, 8, -12, 9, 32, -5};

    if(linearSearch(-5, v, 8)){
        cout << "item encontrado" << endl;
    } else {
        cout << "item nao encontrado" << endl;
    }
}