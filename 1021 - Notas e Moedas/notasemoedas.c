#include <stdio.h>

int main()
{
    double vetor[] = { 100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.1, 0.05, 0.01 };
    int tamanho = 12;
    double entrada, aux;
    aux = 0;

    scanf("%lf", &entrada);
    // printf("%lf\n", entrada);

    int i;
    for(i = 0; i < tamanho; i++) {
        if (vetor[i] < entrada) {
            aux = entrada/vetor[i];
            // printf("%.2lf / %.2lf = %.2lf\n", entrada, vetor[i], aux);
            entrada -= vetor[i] * (int) aux;
        }
        if (i == 0) { printf("NOTAS:\n"); }
        if (i == 6) { printf("MOEDAS:\n"); }
        printf("%.0lf %s(s) de R$ %.2lf\n", aux, (i < 6 ? "nota" : "moeda"), vetor[i]);
        aux = 0.0;
    }

    // printf("%lf\n", entrada);
    return 0;
}
