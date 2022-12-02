#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define troca1(a, b) {int x = a; a = b; b = x; }
#define troca2(a, b) {string x = a; a = b; b = x; }
using namespace std;

typedef struct aluno {
	int matricula;
	string nome;
} Aluno;


void insere(int x, Aluno v[], int n, string nome){
	while(n > 0 && x < v[n-1].matricula){
		v[n].matricula = v[n-1].matricula;
		v[n].nome = v[n-1].nome;
		n--;
	}
	v[n].matricula = x;
	v[n].nome = nome;
}

void ord_insercao(Aluno v[], int tam){
	for(int i = 0; i < tam; i++){
		insere(v[i].matricula, v, i, v[i].nome);
	}
}

int seleciona(Aluno v[], int n){
	int i = 0;
	for (int j = 1; j < n; j++){
		if(v[i].nome < v[j].nome) {
			i = j;
		}
	}
	return i;	
}


void selection_sort(Aluno v[],int n){
	while(n>1){
		troca1(v[seleciona(v,n)].matricula, v[n-1].matricula);
		troca2(v[seleciona(v,n)].nome, v[n-1].nome);
		n--;
	}
};

void bubble_sort(Aluno v[],int n){
	for (int i = 1; i < n-1; i++){
		for (int j = 0; j < n-i; j++){
			if(v[j].matricula > v[j+1].matricula){
				troca1(v[j].matricula, v[j+1].matricula);
				troca2(v[j].nome, v[j+1].nome);
			}
		}
	}
};

void printaAlunos(Aluno v[], int n){
	for (int i = 0; i < 6; i++)
	{
		cout << v[i].nome << " ";
		cout << v[i].matricula;
		cout << endl;
	}
	 	cout << endl;
}

Aluno myarray[20];
	
int main() {

	int mat[] = {0, 36, 66, 1, 16, 24};
	string nomes[] = {"Kairon", "João", "Marisa", "Kelson", "Igor", "Maria", "Kaike"};

	for (int i = 0; i < 6; i++)
	{
		myarray[i].nome = nomes[i];
		myarray[i].matricula = mat[i];
	}

	//1:  A. leia os valores e adicione no vetor de dados
	// ordene pelo campo matricula
	//   B. Ordene por:
	//   c. Insercao
	// mostre o resultado ordenado

	cout << "1. leia os valores e adicione no vetor de dados e ordene pelo campo matricula\n" << endl;

	ord_insercao(myarray, 6);
	printaAlunos(myarray, 6);

	// 2: A. leia os valores e adicione no vetor de dados
	// ordene pelo campo nome 
		//  B. Ordene por:
	//  c. selection_sort
	// mostre o resultado ordenado

	cout << "2. leia os valores e adicione no vetor de dados e ordene pelo campo nome\n" << endl;

	selection_sort(myarray, 6);
	printaAlunos(myarray, 6);
	
	// 3: A. leia os valores e adicione no vetor de dados
	// ordene pelo campo matricula
	//  B. Ordene por:
	//  c. bubble_sort
	// mostre o resultado ordenado

	cout << "3. leia os valores e adicione no vetor de dados e ordene pelo campo matricula\n" << endl;

	bubble_sort(myarray, 6);
	printaAlunos(myarray, 6);
}