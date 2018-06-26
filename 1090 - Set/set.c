#include <stdio.h>
#include <stdlib.h>

/*
    Set com (mesmo simbolo) e (mesma quantidade)
    Set com (mesmo simbolo) e (quantidade diferente)
    Set com (simbolo diferente) e (mesma quantidade)
    Set com (simbolo diferente) e (quantidade diferente)
*/

int configuracoes[][2] = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};

int * copiar(int *vetor) {
    // printf("COPIAR\n");
    int *copia = (int *) calloc(3, sizeof(int));
    int i;
    for (i = 0; i < 3; i++) {
        copia[i] = vetor[i];
    }
    return copia;
}

int set(int mesmaFigura, int mesmaQtd, int *t, int *q, int *c) {
    // printf("SET\n");
    int i;

    // MESMA FIGURA
    if (mesmaFigura) {
        // MESMA QUANTIDADE
        if (mesmaQtd) {
            for (i = 0; i < 3; i++) {
                if (t[i] >= 3) { t[i] -= 3; return 1; }
                if (q[i] >= 3) { q[i] -= 3; return 1; }
                if (c[i] >= 3) { c[i] -= 3; return 1; }
            }
        // QUANTIDADE DIFERENTE
        } else {
            if (t[0] > 0 && t[1] > 0 && t[2] > 0) { t[0]--; t[1]--; t[2]--; return 1; }
            if (q[0] > 0 && q[1] > 0 && q[2] > 0) { q[0]--; q[1]--; q[2]--; return 1; }
            if (c[0] > 0 && c[1] > 0 && c[2] > 0) { c[0]--; c[1]--; c[2]--; return 1; }
        }
    // FIGURA DIFERENTE
    } else {
        // MESMA QUANTIDADE
        if (mesmaQtd) {
            for (i = 0; i < 3; i++) {
                if (t[i] > 0 && q[i] > 0 && c[i] > 0) { t[i]--; q[i]--; c[i]--; return 1; }
            }
        // QUANTIDADE DIFERENTE
        } else {
            if (t[0] > 0) {
                if (q[1] > 0 && c[2] > 0) { t[0]--; q[1]--; c[2]--; return 1; }
                if (c[1] > 0 && q[2] > 0) { t[0]--; c[1]--; q[2]--; return 1; }
            } else if (t[1] > 0) {
                if (q[0] > 0 && c[2] > 0) { t[1]--; q[0]--; c[2]--; return 1; }
                if (c[0] > 0 && q[2] > 0) { t[1]--; c[0]--; q[2]--; return 1; }
            } else if (t[2] > 0) {
                if (q[0] > 0 && c[1] > 0) { t[2]--; q[0]--; c[1]--; return 1; }
                if (c[0] > 0 && q[1] > 0) { t[2]--; c[0]--; q[1]--; return 1; }
            }
            if (q[0] > 0) {
                if (t[1] > 0 && c[2] > 0) { q[0]--; t[1]--; c[2]--; return 1; }
                if (c[1] > 0 && t[2] > 0) { q[0]--; c[1]--; t[2]--; return 1; }
            } else if (q[1] > 0) {
                if (t[0] > 0 && c[2] > 0) { q[1]--; t[0]--; c[2]--; return 1; }
                if (c[0] > 0 && t[2] > 0) { q[1]--; c[0]--; t[2]--; return 1; }
            } else if (q[2] > 0) {
                if (t[0] > 0 && c[1] > 0) { q[2]--; t[0]--; c[1]--; return 1; }
                if (c[0] > 0 && t[1] > 0) { q[2]--; c[0]--; t[1]--; return 1; }
            }
            if (c[0] > 0) {
                if (q[1] > 0 && t[2] > 0) { c[0]--; q[1]--; t[2]--; return 1; }
                if (t[1] > 0 && q[2] > 0) { c[0]--; t[1]--; q[2]--; return 1; }
            } else if (c[1] > 0) {
                if (q[0] > 0 && t[2] > 0) { c[1]--; q[0]--; t[2]--; return 1; }
                if (t[0] > 0 && q[2] > 0) { c[1]--; t[0]--; q[2]--; return 1; }
            } else if (c[2] > 0) {
                if (q[0] > 0 && t[1] > 0) { c[2]--; q[0]--; t[1]--; return 1; }
                if (t[0] > 0 && q[1] > 0) { c[2]--; t[0]--; q[1]--; return 1; }
            }
        }
    }
    return 0;
}

int qtdCartas(int *t, int *q, int *c) {
    return t[0] + t[1] + t[2] + q[0] + q[1] + q[2] + c[0] + c[1] + c[2];
}

int temSet(int *t, int *q, int *c) {
    if (qtdCartas(t, q, c) <3 ) { return 0; }
    return set(1, 1, copiar(t), copiar(q), copiar(c)) ||
           set(1, 0, copiar(t), copiar(q), copiar(c)) ||
           set(0, 1, copiar(t), copiar(q), copiar(c)) ||
           set(0, 0, copiar(t), copiar(q), copiar(c));
}

int qtdSets(int mesmaFigura, int mesmaQtd, int *t, int *q, int *c) {
    // printf("QTD SETS\n");
    int qtd = 0;
    t = copiar(t);
    q = copiar(q);
    c = copiar(c);
    while (set(mesmaFigura, mesmaQtd, t, q, c)) { qtd++; }
    return qtd;
}

void confMaiorQtdSets(int *t, int *q, int *c, int *mesmaFigura, int *mesmaQtd) {
    // printf("CONF MAIOR QTD SETS\n");
    int qtdMesmaMesma = qtdSets(1, 1, copiar(t), copiar(q), copiar(c));
    int qtdMesmaDif = qtdSets(1, 0, copiar(t), copiar(q), copiar(c));
    int qtdDifMesma = qtdSets(0, 1, copiar(t), copiar(q), copiar(c));
    int qtdDifDif = qtdSets(0, 0, copiar(t), copiar(q), copiar(c));

    if (qtdMesmaMesma >= qtdMesmaDif &&
    qtdMesmaMesma >= qtdDifMesma &&
    qtdMesmaMesma >= qtdDifDif) { *mesmaFigura = 1; *mesmaQtd = 1; return; }

    if (qtdMesmaDif >= qtdMesmaMesma &&
    qtdMesmaDif >= qtdDifMesma &&
    qtdMesmaDif >= qtdDifDif) { *mesmaFigura = 1; *mesmaQtd = 0; return; }

    if (qtdDifMesma >= qtdMesmaMesma &&
    qtdDifMesma >= qtdMesmaDif &&
    qtdDifMesma >= qtdDifDif) { *mesmaFigura = 0; *mesmaQtd = 1; return; }

    if (qtdDifDif >= qtdMesmaMesma &&
    qtdDifDif >= qtdMesmaDif &&
    qtdDifDif >= qtdDifMesma) { *mesmaFigura = 0; *mesmaQtd = 0; return; }
}

int maiorQtdSetsRecursivamente(int indiceConfiguracao, int *t, int *q, int *c, int qtdSets) {
    // printf("indice: %d, qtdSets: %d\n", indiceConfiguracao, qtdSets);
    // printf("T: [ %d %d %d ]\n", t[0], t[1], t[2]);
    // printf("Q: [ %d %d %d ]\n", q[0], q[1], q[2]);
    // printf("C: [ %d %d %d ]\n", c[0], c[1], c[2]);
    if (indiceConfiguracao > 3) { return qtdSets; }
    if (set(configuracoes[indiceConfiguracao][0],
            configuracoes[indiceConfiguracao][1],
            t, q, c)) {
        if (temSet(t, q, c)) {
            int outraQtd = maiorQtdSetsRecursivamente(0, copiar(t), copiar(q), copiar(c), qtdSets + 1);
            return outraQtd > qtdSets ? outraQtd : qtdSets;
        } else {
            return qtdSets + 1;
        }
    } else {
        if (temSet(t, q, c) && indiceConfiguracao < 3) {
            return maiorQtdSetsRecursivamente(indiceConfiguracao + 1, copiar(t), copiar(q), copiar(c), qtdSets);
        } else {
            return qtdSets;
        }
    }
}

void calcularMaiorQtdDeSets(int *t, int *q, int *c) {
    // printf("CALCULAR MAIOR QTD DE SETS\n");
    // int qtdSets = 0;
    // printf("\nT: [ %d %d %d ]\n", t[0], t[1], t[2]);
    // printf("Q: [ %d %d %d ]\n", q[0], q[1], q[2]);
    // printf("C: [ %d %d %d ]\n", c[0], c[1], c[2]);
    // while (temSet(copiar(t), copiar(q), copiar(c))) {
    //     int mesmaFigura;
    //     int mesmaQtd;
    //     confMaiorQtdSets(copiar(t), copiar(q), copiar(c), &mesmaFigura, &mesmaQtd);
    //     while(set(mesmaFigura, mesmaQtd, t, q, c)) { qtdSets++; }
    // }
    printf("%d\n", maiorQtdSetsRecursivamente(0, t, q, c, 0));
}

int main() {

    int qtdCartas;
    scanf("%d", &qtdCartas);
    // printf("%d\n", qtdCartas);
    while (qtdCartas > 0) {
        int i;
        int *triangulos;
        int *quadrados;
        int *circulos;

        triangulos = (int *) calloc(3, sizeof(int));
        quadrados = (int *) calloc(3, sizeof(int));
        circulos = (int *) calloc(3, sizeof(int));

        for ( i = 0; i < qtdCartas; i++) {
            char *qtd = (char *) calloc(4, sizeof(char));
            char *forma = (char *) calloc(10, sizeof(char));
            scanf("%s %s", qtd, forma);
            // printf("%s %s\n", qtd, forma);
            int indiceQtd = (qtd[0] == 'u') ? 0 : (qtd[0] == 'd') ? 1 : 2 ;
            if (forma[0] == 't') {
                triangulos[indiceQtd] = triangulos[indiceQtd] + 1;
            } else if (forma[0] == 'q') {
                quadrados[indiceQtd] = quadrados[indiceQtd] + 1;
            } else {
                circulos[indiceQtd] = circulos[indiceQtd] + 1;
            }
        }

        calcularMaiorQtdDeSets(triangulos, quadrados, circulos);

        scanf("%d", &qtdCartas);
        // printf("%d\n", qtdCartas);
    }

    return 0;
}
