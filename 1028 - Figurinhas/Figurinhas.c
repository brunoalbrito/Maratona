#include <stdio.h>
#include <stdlib.h>

int mdc(int num1, int num2);

int main (){

    int rep, i;
    scanf("%d", &rep);

    for(i = 0; i < rep; i++){
        int a, b, resultado;
        scanf("%d %d", &a, &b);

        resultado = mdc(a, b);

        printf("%d\n", resultado);
    }

}

int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}
