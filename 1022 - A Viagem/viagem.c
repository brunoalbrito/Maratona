#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int n;
    scanf("%d", &n);
    while (n) {
        // printf("\n");

        float *gastos = (float *) calloc(n, sizeof(float));
        float totalGastos = 0.0;

        for (i = 0; i < n; i++) {
            scanf("%f", &gastos[i]);
            totalGastos += gastos[i];
            // printf("%.2f\n", gastos[i]);
        }
        // printf("Gasto total: %f\n", totalGastos);

        int totalReais = totalGastos;
        int totalCentavos = (totalGastos - totalReais) * 100;
        // printf("Reais: %d, Centavos: %d\n", totalReais, totalCentavos);

        int mediaReais = totalReais / n;
        int mediaCentavos = (float)((float)(totalReais % n) / n) * 100;
        // printf("Média Reais: %d, Média Centavos: %d\n", mediaReais, mediaCentavos);

        int totalTrocaReais = 0;
        int totalTrocaCentavos = 0;
        for (i = 0; i < n; i++) {
            if (gastos[i] < mediaReais) {
                int trocaReais = mediaReais - gastos[i];
                int trocaCentavos = (float)((float)((float) mediaReais - trocaReais) - gastos[i]) * 100;
                totalTrocaReais += trocaReais;
                totalTrocaCentavos += trocaCentavos;
            }
        }
        if (totalCentavos >= n) {
            totalTrocaCentavos += (totalCentavos / n);
        }
        if (totalTrocaCentavos >= 100) {
            totalTrocaReais += totalTrocaCentavos / 100;
            totalTrocaCentavos = totalTrocaCentavos - (100 * (totalTrocaCentavos / 100));
        }
        // printf("Total Troca Reais: %d, Total Troca Centavos: %d\n", totalTrocaReais, totalTrocaCentavos);

        printf("$%d.%d\n", totalTrocaReais, totalTrocaCentavos);

        free(gastos);
        scanf("%d", &n);
    }
    return 0;
}
