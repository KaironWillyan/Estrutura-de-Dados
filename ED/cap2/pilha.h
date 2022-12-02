#include <stdio.h>
#include <stdlib.h>

typedef float* ItemPilha;

typedef struct pilha {
    int max;  // Capacidade da pilha
    int topo; // Posição do topo
    ItemPilha *item; // Itens da pilha
} *Pilha;

int ehPilhaSVazia(Pilha pilha) {
    return pilha->topo == -1;
}

int ehPilhaSCheia(Pilha pilha) {
    return pilha->topo == pilha->max-1;
}

Pilha criarPilha(int tamanho) {
    Pilha pilha = (Pilha)malloc(sizeof(struct pilha)); 

    pilha->max = tamanho; 
    pilha->topo = -1; 
    pilha->item = (ItemPilha*)malloc(sizeof(ItemPilha) * tamanho);

    return pilha;
}

void push(ItemPilha itemp, Pilha pilha) { 
    
    if( !ehPilhaSCheia(pilha)) {
        pilha->topo++;
        pilha->item[pilha->topo] = itemp; 
    }

}

ItemPilha pop(Pilha pilha) {
    
    if( !ehPilhaSVazia(pilha)) {
        ItemPilha item = pilha->item[pilha->topo];
        pilha->topo--;
        
        return item;
    }
}

void showPilha(Pilha pilha) {

    while(!ehPilhaSVazia(pilha)) {
        printf("%s", pop(pilha));
        }
        printf("\n");
}

void destruirPilha(Pilha* ponteiroPilha) {
    
    free((*ponteiroPilha)->item);
    free(ponteiroPilha);
    ponteiroPilha = NULL;
}

ItemPilha getTopoS(Pilha pilha) {

    if( ehPilhaSVazia(pilha)) { puts("A pilha está vazia!"); abort(); }
    return pilha->item[pilha->topo];

}