#include <stdio.h>
#include <stdlib.h>

int proximoIndice(int inicio, int *morreu, int qtdPessoas, int intervalo) {
    int proximo;
    proximo = inicio;
    while (intervalo) {
        if (proximo + 1 < qtdPessoas) {
            proximo++;
        } else {
            proximo = 0;
        }
        if (!morreu[proximo]) { intervalo--; }
    }
    return proximo;
}

int restaSomenteUm(int *morreu, int qtdPessoas) {
    int i, qtd;
    qtd = 0;
    for (i = 0; i < qtdPessoas; i++) {
        if (!morreu[i]) { qtd++; }
        if (qtd > 1) { return 0; }
    }
    return 1;
}

int indicePrimeiroVivo(int *morreu, int qtdPessoas) {
    int i;
    for (i = 0; i < qtdPessoas; i++) {
        if (!morreu[i]) { return i; }
    }
    return 0;
}

int main() {
    int casos, i;
    scanf("%d", &casos);
    for (i = 0; i < casos; i++) {
        int qtdPessoas, intervalo;
        scanf("%d %d", &qtdPessoas, &intervalo);
        int *morreu = (int *) calloc(qtdPessoas, sizeof(int));
        int indiceUltimoMorto = 0;
        while (!restaSomenteUm(morreu, qtdPessoas)) {
            int indiceProximoMorto = proximoIndice(indiceUltimoMorto, morreu, qtdPessoas, intervalo);
            morreu[indiceProximoMorto] = 1;
            indiceUltimoMorto = indiceProximoMorto;
        }
        printf("Case %d: %d\n", (i+1), indicePrimeiroVivo(morreu, qtdPessoas));
        free(morreu);
    }
    return 0;
}
