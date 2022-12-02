#include <iostream>

using namespace std;

template <class T>

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

        int vazia() {
            return topo == -1;
        }

        int cheia() {
            return topo == max-1;
        }

        int getTopo() {
            return topo;
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
        }

        void fullUnstack() {
            while (!cheia()) pop();
            free(item);
            free(&max);
            free(&topo);
            
        }
};