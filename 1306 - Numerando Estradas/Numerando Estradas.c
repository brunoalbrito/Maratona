#include <stdio.h>

int main(){

    int r = 1, n = 1, cont = 1;

    while(r != 0 && n !=0){
        int d = 0;
        scanf("%d %d", &r, &n);
        int r1 = r;
        if (r == 0 && n ==0)
            break;

        while(r1 > n){
            d = d + 1;
            r1 = r1 - n;
        }

        if(r <= n * 27)
            printf("Case %d: %d\n",cont, d);
        else
            printf("Case %d: impossible\n", cont);

        cont++;
    }

}
