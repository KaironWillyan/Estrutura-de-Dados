#include<stdio.h>
#include<iostream>
#include <string.h>
using namespace std;
#define troca1(a, b) {int x = a; a = b; b = x; }

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

void bubble_sort(int v[],int n){
	for (int i = 1; i < n-1; i++){
		for (int j = 0; j < n-i; j++){
			if(v[j] > v[j+1]){
				troca1(v[j], v[j+1]);
			}
		}
	}
};

int main(){

   int mat[] = {0, 36, 66, 1, 16, 24};


   if(linearSearch(3, mat, 6)){
      cout << "item encontrado" << endl;
   } else {
      cout << "item nao encontrado" << endl;
   } 

   bubble_sort(mat, 6);

   if(binarySearch(36, mat, 6, 0)){
      cout << "item encontrado" << endl;
   } else {
      cout << "item nao encontrado" << endl;
   }

   
}