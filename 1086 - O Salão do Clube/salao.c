#include <stdio.h>
#include <stdlib.h>

void print(int *v, int size) {
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) { printf("%d ", v[i]); }
    printf("]\n");
}

int * copiar(int *vetor, int tamanho) {
    // printf("COPIAR\n");
    int *copia = (int *) calloc(tamanho, sizeof(int));
    int i;
    for (i = 0; i < tamanho; i++) {
        copia[i] = vetor[i];
    }
    return copia;
}

/*
 Diz se um salao é forrável a partir de sua largura.
    Argumentos
    larguraSalao: largura do salão em metros
    larguraTabua: largura das tábuas em centimentros
*/
int ehForravel(int larguraSalao, int larguraTabua) {
    return !((larguraSalao * 100) % larguraTabua);
}

/*
 Tenta pegar o indice da tábua que seja maior ou igual ao tamanho indicado.
 Caso seja maior, tenta pegar o indice da menor tábua.
 Caso não haja tábua de tamanho maior ou igual ao desejado, pega a maior.
 Argumentos
     tabuas: Array com o altura das tábulas em metros
     k: Quantidade de tábuas
     tamanho: Tamanho da tábua procurada em metros
*/
int escolher(int *tabuas, int k, int tamanho) {
    int indice, auxMaior, auxMenor, i;
    indice = -1;
    auxMaior = 0;
    auxMenor = 0;
    for (i = 0; i < k; i++) {
        if (tabuas[i] == tamanho) { return i; } // Se tamanho igual
        if (tabuas[i] && tabuas[i] < tamanho) {
            if (auxMenor) { // Tenta pegar a maior tábua possível
                 if (tabuas[i] > auxMenor) {
                     auxMenor = tabuas[i];
                     indice = i;
                 }
            } else {
                auxMenor = tabuas[i];
                indice = i;
            }
        }
        // if (tabuas[i] > tamanho) { // Se tamanho for maior
        //     if (auxMaior) { // Tenta pegar a menor tábua possível
        //         if (tabuas[i] < auxMaior) {
        //             auxMaior = tabuas[i];
        //             indice = i;
        //         }
        //     } else {
        //         auxMaior = tabuas[i];
        //         indice = i;
        //     }
        // } else if (!auxMaior) { // Se não tem maior e tamanho atual é menor
        //     if (auxMenor) { // Tenta pegar a maior tábua possível
        //          if (tabuas[i] > auxMenor) {
        //              auxMenor = tabuas[i];
        //              indice = i;
        //          }
        //     } else {
        //         auxMenor = tabuas[i];
        //         indice = i;
        //     }
        // }
    }
    return indice;
}

/*
 Tenta preencher a área algura x largura dispondo as tábuas na vertiacal.
 Se der bom, retorna o número de tábuas que devem ser usada.
 Se der ruim, retorna 0, indicando que é impossível forrar a área.
 Argumentos:
    tabuas: Array com o altura das tábulas em metros
    k: Quantidade de tábuas
    l: Largura das tábuas em centimetros
    altura: altura do salão em metros
    largura: largura do salão em metros
*/
int forrar(int *tabuas, int k, int l, int altura, int largura) {
    printf("A: %d, L: %d\n\n", altura, largura);

    if (!ehForravel(largura, l)) { return 0; }
    int qtdTabuasUsadas, *usou, i, qtdFileiras, h, jahPossuiEmenda;
    qtdTabuasUsadas = 0;
    usou = (int *) calloc(k, sizeof(int)); // Estrutura auxiliar para dizer se a tábua já foi usada
    qtdFileiras = (largura * 100)/l; // Qtd de fileiras de madeiras necessárias a partir da largura da sala e das tábuas
    h = altura;
    jahPossuiEmenda = 0;

    for (i = 0; i < qtdFileiras; i++) {
        while (h) {
            printf("H: %d\n", h);
            printf("T: "); print(tabuas, k);
            printf("U: "); print(usou, k); //printf("\n");
            int indiceTabua = escolher(tabuas, k, h);
            printf("I: %d (%d), para %d\n\n", indiceTabua, tabuas[indiceTabua], h);
            if (indiceTabua == -1) { return 0; }
            if (tabuas[indiceTabua] >= h) {
                tabuas[indiceTabua] -= h;
                h = 0;
            } else {
                if (jahPossuiEmenda) { return 0; }
                h -= tabuas[indiceTabua];
                tabuas[indiceTabua] = 0;
                jahPossuiEmenda = 1;
            }
            if (!usou[indiceTabua]) {
                qtdTabuasUsadas++;
                usou[indiceTabua] = 1;
            }
        }
        h = altura;
        jahPossuiEmenda = 0;
    }

    free(usou);
    return qtdTabuasUsadas;
}

int main() {
    // Cumprimento da sala em metros (m x n), largura das tábuas em cm, qtd de tábuas, altura de cada tábua em metros
    int m, n, l, k, *tabuas, i;

    scanf("%d %d", &m, &n);
    while(m && n) {
        scanf("%d", &l);
        scanf("%d", &k);
        tabuas = (int *) calloc(k, sizeof(int));
        for (i = 0; i < k; i++) {
            scanf("%d", &tabuas[i]);
        }
        int forrou;
        forrou = forrar(copiar(tabuas, k), k, l, m, n);
        if (!forrou) { forrou = forrar(tabuas, k, l, n, m); }
        if (forrou) { printf(" FIM %d\n", forrou); } else { printf(" FIM impossivel\n"); }
        free(tabuas);
        scanf("%d %d", &m, &n);
    }

    return 0;
}
