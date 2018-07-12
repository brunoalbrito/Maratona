#include <stdio.h>
#include <stdlib.h>

int main (){

    int numero1 = 1, numero2 = 1;

    while(numero1 != 0 && numero2 != 0){
        int resultado = 0, comp = 0, i = 0, j = 0, p = 0;
		scanf("%d %d", &numero1, &numero2);

        if(numero1 == 0 && numero2 == 0)
            break;

        while(numero1 > 0 || numero2 > 0){
            if ( (numero1%10 + numero2%10 + p) > 9 ){
                resultado++;
                p = 1;
            } else {
                p = 0;
            }

            numero1 = numero1/10;
            numero2 = numero2/10;
        }


        if (resultado == 0) {
            printf("No carry operation.\n");
        } else if(resultado == 1) {
            printf("%d carry operation.\n", resultado);
        } else {
            printf("%d carry operations.\n", resultado);
        }
        numero1 = 1;
        numero2 = 1;
    }
}
