#include <stdio.h>
#include "./pilha.h" // Pilha de float

int main() {
    int tam;
    ItemPilha item;
    ItemPilha aux;

    printf("Qtd de numeros: ");
    scanf("%d", &tam);

    Pilha pilhaB = criarPilha(tam);
    Pilha pilhaA = criarPilha(tam);

    printf("Itens: ");
    for(int i = 0; i < tam; i++) {
        scanf("%f", &item);
        push(item, pilhaB);
    }

    printf("Tranquilo \n");
    while(!ehPilhaSVazia(pilhaB)) {
        if (ehPilhaSVazia(pilhaA) || pilhaA->item[pilhaA->topo] >= pilhaB->item[pilhaB->topo]) {
            push(pop(pilhaB), pilhaA);
        } else {
            aux = pop(pilhaB);
            printf("aux: %.2f\n", aux);

            while (!ehPilhaSVazia(pilhaA) && pilhaA->item[pilhaA->topo] < aux) {
                push(pop(pilhaA), pilhaB);
            }
            push(aux, pilhaA);
        }
    }

    showPilha(pilhaA);

    system("pause");
}

