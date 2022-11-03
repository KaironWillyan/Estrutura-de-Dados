#include <iostream>
#include <cmath>

using namespace std;

typedef struct poli {
    float coeficiente;
    int expoente;
    struct poli *prox;
    
} *Poli;

Poli termo(float coeficiente, int expoente, Poli proximo) {
    Poli n = (poli*)malloc(sizeof(struct poli));
    n->coeficiente = coeficiente;
    n->expoente = expoente;
    n->prox = proximo;

    return n;
}

void exibirPolinomio(Poli polinomio) {
    if(polinomio == NULL) return;
    printf("%+.1f", polinomio->coeficiente);
    if(polinomio->expoente != 0) printf("*x^%d", polinomio->expoente);
    exibirPolinomio(polinomio->prox);
}

void addTermo(float coeficiente, int expoente, Poli *polinomio) {
    if(*polinomio == NULL || (*polinomio)->expoente < expoente) {
        *polinomio = termo(coeficiente, expoente, *polinomio);
    } else if((*polinomio)->expoente == expoente) {
        (*polinomio)->coeficiente += coeficiente;
        if((*polinomio)->coeficiente == 0) {
            Poli n = *polinomio;
            *polinomio = n->prox;
            free(n);
        }
    } else {
        addTermo(coeficiente, expoente, &(*polinomio)->prox);
    }
}

float valor(Poli polinomio, float x) {
    if(polinomio == NULL) return 0;
    else {
        return polinomio->coeficiente * pow(x, polinomio->expoente) + valor(polinomio->prox, x);
    } 
}

Poli derivada(Poli polinomio) {
    if(polinomio == NULL || polinomio->expoente == 0) return NULL;
    return termo(polinomio->coeficiente * polinomio->expoente, polinomio->expoente - 1, derivada(polinomio->prox));
}

void destruirPolinomio(Poli *polinomio) {
    if( (*polinomio) == NULL) return;
    destruirPolinomio(&(*polinomio)->prox);
    free(*polinomio);
    *polinomio = NULL;
}
