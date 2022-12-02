#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct aluno{
	int mat;
	string nome;	
}Aluno; 

Aluno lista[30];
int contador = 0;
//retorna a posicao do elemento procurado
int procura(int mat){	
	int tam = contador;
	for(int i = 0; i < tam; i++){
		if(lista[i].mat == mat){
			return i;
		}
	}
	return -1;
}
void incluirDesordenado(Aluno e){
	if(procura(e.mat) == -1){
		lista[contador] = e;
		contador++;
	}
}
//recebe a posicao e imprime o elemento na tela
void mostrar(int pos){
	cout << "\tAluno: " << lista[pos].nome << endl;
	cout << "\tMatricula: " << lista[pos].mat << endl;
}
//procura o elemento e depois mostra o elemento encontrado (se nao for encontrado informa q ele nao existe)
void consultar(int mat){	
	int posAlu = procura(mat);
	if(posAlu != -1){
		mostrar(posAlu);
	}else{
		cout << "Aluno nao encontrado" << endl;
	}
}

//estrategia 1: colocar o ultimo elemento da lista na posicao do elemento removido
void remover00(int mat){
	int pos = procura(mat);
	lista[pos] = lista[contador];
	free(&lista[contador]);
	contador--;
}

//estrategia 2: mover TODOS os elementos que estao APOS  o elemento que deve ser removido UMA POSICAO A FRENTE.
void remover01(int mat){
	int pos = procura(mat);

	for(int i = pos; i < contador; i++){
		lista[i] = lista[i+1];
	}

	free(&lista[contador]);
	contador--;
}

main(){
	Aluno aluno1;
	aluno1.mat = 1;
	aluno1.nome = "Kairon";
	///////////
	Aluno aluno2;
	aluno2.mat = 2;
	aluno2.nome = "Joao";
	///////////
	Aluno aluno3;
	aluno3.mat = 3;
	aluno3.nome = "Romero";
	///////////
	Aluno aluno4;
	aluno4.mat = 4;
	aluno4.nome = "Kaike";
	///////////
	Aluno aluno5;
	aluno5.mat = 5;
	aluno5.nome = "Kelson";
	///////////
	incluirDesordenado(aluno1);
	incluirDesordenado(aluno2);
	incluirDesordenado(aluno3);
	incluirDesordenado(aluno4);
	incluirDesordenado(aluno5);

	mostrar(0);
	mostrar(1);
	mostrar(2);
	mostrar(3);
	mostrar(4);
	return 0;
}

