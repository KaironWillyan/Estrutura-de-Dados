#include <queue>
#include <iostream>
using namespace std;

template <class T>
class Queue: public queue<T> {
	protected:
		queue<T> _fila;
	public:

	T popQueue() {
		T tmp=_fila.front();
		_fila.pop();
		return tmp;
	}
	
	
	void popTodos() {	
		while(!_fila.empty()) {
			cout << popQueue() << endl;
		} 
    }
    
    void simulaPilha(T novo) {
		_fila.push(novo);
		while (_fila.front() != novo) {
			_fila.push(popQueue());
		} 
	}
};

main(){
	Queue<int> fila;

	fila.simulaPilha(1);
	fila.simulaPilha(2);
	fila.simulaPilha(3);
	fila.simulaPilha(4);
	fila.simulaPilha(5);
	fila.simulaPilha(6);
	fila.simulaPilha(7);

	cout << "->" << fila.popQueue() << endl;
	fila.popTodos();
}