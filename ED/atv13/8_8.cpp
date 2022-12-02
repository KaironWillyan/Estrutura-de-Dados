#include<stdio.h>
#include<iostream>
#define troca(a, b) {int x = a; a = b; b = x; }

using namespace std;
void quickSort(int vetor[10], int inicio, int fim);
int main(){
   printf("Alternativa a\n");   
   int vetor[7] = {72,69,51,46,33,28,15};
   int i;   
   quickSort(vetor, 0, 6);
   printf("\n2.Vetor ordenado:\n");
   for(i = 0; i <= 6; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");   

   printf("\nAlternativa b\n");
   int vetor2[7] = {46,28,51,33,72,15,69};
   int j;   
   quickSort(vetor2, 0, 6);
   printf("\n2.Vetor ordenado:\n");
   for(j = 0; j <= 6; j++){
      printf("%d ", vetor2[j]);
   }
   printf("\n");  



}

int particiona (int v[], int inicio, int fim) {
    int x = v[inicio];
    inicio--;
    fim++;
    while(inicio<fim){
        do fim--; while(v[fim]>x);
        do inicio++; while(v[inicio]<x);
        if (inicio < fim) troca(v[inicio], v[fim]);
    }
    return fim;
}

void quickSort(int v[], int inicio, int fim){
    if(inicio >= fim) return;
    int m = particiona(v, inicio, fim);
    quickSort(v, inicio, m);
    quickSort(v, m+1, fim);
}