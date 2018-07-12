#include <stdio.h>

int main(){


    long long int proprio, oponentes;
    while( scanf("%lld %lld", &proprio, &oponentes) != EOF) {

        if(proprio > oponentes)
            printf("%lld\n", proprio - oponentes);
        else if(oponentes > proprio)
            printf("%lld\n", oponentes - proprio);
        else
            printf("0\n");

    }
}
