#include <iostream>
#include "pilha.hpp"

using namespace std;

bool ehOperador(char item) {
    return item == '~' || item == '&' || item =='|';
}

bool ehOperando(char item) {
    return !ehOperador(item) && item != '(' && item != ')';
}

int prioridade(char item) {
    switch (item) {
    case '(': return 0; break;
    case '|': return 1; break;
    case '&': return 2; break;
    case '~': return 2; break;
    
    }
}

int valorLogico(char letra) {
    if(letra == 'V') return 1;
    else return 0;
}

string converterParaPosfixa(string infixa) {
    string posfixa = "";
    Pilha<char> pilhasOp(infixa.length()); // Pilha de char

    for (int i = 0; i < infixa.length(); i++) {
        if(infixa[i] == '(') pilhasOp.push('(');
        else if(ehOperando(infixa[i])) posfixa += infixa[i];
        else if(ehOperador(infixa[i])) {
            while (!pilhasOp.vazia() && (prioridade(pilhasOp.getTopo()) >= prioridade(infixa[i]))){
                posfixa += pilhasOp.pop();
            }
            
            pilhasOp.push(infixa[i]);
        } else {
            while (pilhasOp.getTopo() != '(') {
                posfixa += pilhasOp.pop();
            }
            pilhasOp.pop();
        }
    }

    while (!pilhasOp.vazia()) {
        posfixa += pilhasOp.pop();
    }
        

    return posfixa;
}

char calcularValorExpressao(string exp) {
    Pilha<float> pilhaExp(exp.length()); // Pilha de int
    float x, y, result;

    for (int i = 0; i < exp.length(); i++) {
        if(ehOperando(exp[i])) {
            pilhaExp.push(valorLogico(exp[i]));
            while (ehOperando(exp[i+1]) || exp[i+1] == '.') {
                i++;
                };
        } else if(ehOperador(exp[i])) {
            y = pilhaExp.pop();
            x = pilhaExp.pop();
            switch (exp[i]){
                case '|': pilhaExp.push(x||y); break;
                case '&': pilhaExp.push(x&&y); break;
                case '~': pilhaExp.push(x && !y); break;
            }
        }
    }

    result = pilhaExp.pop();
    
    if(result == 1) return 'V';
    else return 'F';
}

int main() {
    string infixa = "(V&(F|V)&(~F))";

    string posfixa = converterParaPosfixa(infixa);

    char resultado = calcularValorExpressao(posfixa);

    cout << "Posfixa: " << posfixa << endl;
    cout << "Resultado: " << resultado << endl;
}