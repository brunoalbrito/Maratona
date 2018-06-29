#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehMaiuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

int ehMinuscula(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {

    int qtdCasosDeTeste, i;
    scanf("%d", &qtdCasosDeTeste);

    for (i = 0; i < qtdCasosDeTeste; i++) {
        char *string = (char *) malloc(sizeof(char));
        scanf("%[^\n]", string);
        int tamanhoString = strlen(string);
        char *stringInvertida = (char *) calloc(tamanhoString, sizeof(char));

        // 1 - MAIÚSCULAS E MINÚSUCAS DESLOCADOS TRÊS PARA A DIREITA
        int j;
        int k = tamanhoString - 1;
        for (j = 0; j < tamanhoString; j++) {
            char c = string[j];
            if (ehMaiuscula(c) || ehMinuscula(c)) {
                string[j] += 3;
            }

            // 2 - INVERTER STRING
            stringInvertida[k--] = string[j];

            // 3 - DESCOLAR UM PARA ESQUERDA DA METADE EM DIANTE
            if (j > (tamanhoString/2 - 1)) {
                stringInvertida[j]--;
            }

        }
        string = stringInvertida;
        printf("%s\n", string);
        // 3 -

        free(string);
    }

    return 0;
}
