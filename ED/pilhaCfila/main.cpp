#include <iostream>

using namespace std;
class No {
    public:
    char nome;
    No *prox;
    
    No(char n) {
        nome=n;
        prox=NULL;
    }

};

class Fila{
    public:
    No *inicio;
    No *fim;
    
    Fila() {
        inicio = NULL;
        fim = NULL;
    }

    //inserir um elemento no topo da fila
    void insereNaFila(char n) {
        No *novo= new No(n);

        if (inicio==NULL) { //fila vazia
            inicio = novo;
            fim = novo;
        } else { // insere o elemento e modifica o topo
            fim->prox=novo;
            fim=novo;
        }
    }

    //retirar o elemento do topo
    char retiraDaFila() {
        No *el;
        char nome;
        
        if (inicio!=NULL) {
            el=inicio;
            nome=el->nome;
            inicio=inicio->prox;
            free(el);
        }
        return nome;
    }

    int fila_vazia() {
        return (inicio==NULL);
    }

    void mostra(){
        No *atual;
        atual=inicio;
        cout << "\n\n--------Mostra a Fila---------------\n\n";
        while (atual!=NULL) {
            printf("\nNome %c\n", atual->nome);
            atual = atual->prox;
        }
    }
};


main(){
    Fila *f1=new Fila();
    Fila *f2=new Fila();
    int resp;
    char letra;
    do {
        cout <<"\nDigite a letra:";
        cin >> letra; // Cada letra lida deve ser empilhada, mas so e possível usar os metodos da classe Fila

        if(f1->fila_vazia()) {
            f1->insereNaFila(letra);
        } else {
            while (!f1->fila_vazia()) {
                f2->insereNaFila(f1->retiraDaFila());
            }

            f1->insereNaFila(letra);
            while (!f2->fila_vazia()) {
                f1->insereNaFila(f2->retiraDaFila());
            }

        }

        cout << "\nDeseja continuar (1-Sim 2-Nao)?";
        cin >> resp;
    } while(resp==1);

    f1->mostra();
}