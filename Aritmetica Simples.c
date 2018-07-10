#include <stdio.h>
#include <stdlib.h>

int main (){

    int numero1 = 10, numero2 = 10;
    int * num1 = (int*)calloc(9, sizeof(int));
    int * num2 = (int*)calloc(9, sizeof(int));
    scanf("%d %d", &numero1, &numero2);
    int i = 0, j = 0;
    while(numero1 != 0 && numero2 != 0){
        int resultado = 0, comp = 0;
        while(numero1 > 0){
            num1[i] = numero1%10;
            numero1 = numero1/10;
            i++;
        }
        while(numero2 > 0){
            num2[j] = numero2%10;
            numero2 = numero2/10;
            j++;
        }

        while(num1[comp] > 0 && num2[comp] > 0){
            if(num1[comp] + num2[comp] > 9){
                resultado++;
                comp++;
            } else {
                comp++;
            }

        }
        if (resultado == 0) {
            printf("No carry operation.\n");
        } else if(resultado == 1) {
            printf("%d carry operation.\n", resultado);
        } else {
            printf("%d carry operations.\n", resultado);
        }

        free(num1);
        free(num2);
        scanf("%d %d", &numero1, &numero2);

    }
}
