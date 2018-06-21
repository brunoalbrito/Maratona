#include <stdio.h>

int main()
{
    int valores[] = {100, 50, 20 , 10 , 5, 2 , 1}, tamanho = 7,
    qtdValores[7] , entrada;

    scanf("%d", &entrada);
    printf("%d\n", entrada);
    int i;
    for(i = 0; i < tamanho; i++){
        qtdValores[i] = entrada / valores[i];
        entrada = entrada % valores[i];
        printf("%d nota(s) de R$ %d,00\n", qtdValores[i], valores[i]);
    }
    return 0;
}
