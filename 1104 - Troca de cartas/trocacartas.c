#include <stdio.h>
#include <stdlib.h>

// FUNÇÃO AUXILIAR QUE DEVE SER PASSADA POR PARÂMETRO NA BUSCA BINÁRIA
int comparationFunction(const void * a, const void * b) {
   return ( (*(int*)a) - (*(int*)b) );
}

int amountOfEqualsElements(int *a, int sizeA, int *b, int sizeB) {
    int size, i, *item;
    size = 0;
    // PERCORRENDO OS ELEMENTOS DE A E OS PROCURANDO EM B
    for (i = 0; i < sizeA; i++) {
        // USANDO A FUNÇÃO DE BUSCA BINÁRIA DA BIBLIOTECA PADRÃO PARA FAZER A BUSCA
        item = (int*) bsearch (&a[i], b, sizeB, sizeof(int), comparationFunction);
        if (item) { size++; }
    }
    return size;
}

void print(int *v, int size) {
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) { printf("%d ", v[i]); }
    printf("]\n");
}

int main() {
    int a, b, i, lastCard, aux;
    int *alice, *beatriz;
    int differentCardsA, differentCardsB;

    a = 0; b = 0;
    differentCardsA = 0;
    differentCardsB = 0;

    scanf("%d %d", &a, &b);
    while(a && b) {

        alice = (int *) calloc(a, sizeof(int));
        beatriz = (int *) calloc(b, sizeof(int));

        scanf("%d", &lastCard);
        alice[0] = lastCard;
        differentCardsA++;
        for (i = 1; i < a; i++) {
            scanf("%d", &aux);
            if (aux != lastCard) {
                alice[differentCardsA++] = aux;
                lastCard = aux;
            }
        }

        scanf("%d", &lastCard);
        beatriz[0] = lastCard;
        differentCardsB++;
        for (i = 1; i < b; i++) {
            scanf("%d", &aux);
            if (aux != lastCard) {
                beatriz[differentCardsB++] = aux;
                lastCard = aux;
            }
        }

        // print(alice, differentCardsA);
        // print(beatriz, differentCardsB);
        // printf("Amount of equals elements: %d\n", amountOfEqualsElements(alice, differentCardsA, beatriz, differentCardsB));

        int equals = amountOfEqualsElements(alice, differentCardsA, beatriz, differentCardsB);
        printf("%d\n", (differentCardsA > differentCardsB ? differentCardsB : differentCardsA) - equals);

        free(alice);
        free(beatriz);

        a = 0; b = 0;
        differentCardsA = 0;
        differentCardsB = 0;
        scanf("%d %d", &a, &b);
    }
    return 0;
}
