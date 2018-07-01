#include <stdio.h>

int main()
{
    double vetor[] = {100, 50, 20, 10, 5, 2, 1,0.50, 0.25, 0.10, 0.05, 0.01};
    int tamanho = 12, notas[12];
    double entrada;
    
    scanf("%lf", &entrada);
    
    int i;
    for(i = 0; i < tamanho; i++){
        if( i < 6){
            if(i == 0) printf("NOTAS:\n");
            notas[i] = ((int) (entrada / vetor[i]));
            entrada = entrada - (vetor[i] * notas[i]);
            printf("%d nota(s) de R$ %2.2lf\n", notas[i], vetor[i]);
        }else{
            notas[i] = ((int) (entrada / vetor[i]));
            entrada = entrada - (vetor[i] * notas[i]);
            if(i == 6){
                printf("MOEDAS:\n");
                printf("%d moeda(s) de R$ %2.2lf\n", notas[i], vetor[i]);
            }
            else{
                printf("%d moeda(s) de R$ %2.2lf\n", notas[i], vetor[i]);
            }
        }
    }

    return 0;
}
