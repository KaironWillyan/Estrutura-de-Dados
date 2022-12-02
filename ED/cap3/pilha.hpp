#include <iostream>

using namespace std;

template <typename T>

class Pilha {
    public:
        int max;
        int topo;
        T * item;

        Pilha(int tamanho) {
            max = tamanho;
            topo = -1;
            item =  new T[tamanho];
        }

        bool vazia() {
            return topo == -1;
        }

        bool cheia() {
            return topo == max-1;
        }

        T getTopo() {
            return item[topo];
        }

        void push(T itemp) {
            if( !cheia()) {
                topo++;
                item[topo] = itemp;
            }
        }

        T pop() {
            if( !vazia()) {
                T itemT = item[topo];
                topo--;
                
                return itemT;
            }
            throw exception;
        }

        void fullUnstack() {
            while (!cheia()){
                cout << pop() << endl;
            }
            
        }
};
