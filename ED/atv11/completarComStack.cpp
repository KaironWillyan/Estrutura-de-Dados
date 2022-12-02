#include <stack>
#include <iostream>
using namespace std;

template <class T>
class Stack: public stack<T> {
	protected:
		stack<T> pilha;
	public:

	T popStack(){ 
		T tmp = pilha.top();
		pilha.pop();
		return tmp;
	}
	
	
	void popTodos(){
		while (!pilha.empty()) {
			cout << popStack() << endl;
		}
    }
	
	void simulaFila(T novo){
		stack<T> pilhaManobra;
		
		while (!pilha.empty()) {
			pilhaManobra.push(popStack());
		}
		pilha.push(novo);
		
		while (!pilhaManobra.empty()) {
			pilha.push(pilhaManobra.top());
			pilhaManobra.pop();
		}

		free(&pilhaManobra);
	}
	
	
};

main() {
	Stack<int> fila;

	fila.simulaFila(1);
	fila.simulaFila(2);
	fila.simulaFila(3);
	fila.simulaFila(4);
	fila.simulaFila(5);
	fila.simulaFila(6);


	fila.popTodos();
}