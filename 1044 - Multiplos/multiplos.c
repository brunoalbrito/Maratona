#include <stdio.h>

int main(){
    int x1, x2;

    scanf("%d %d", &x1, &x2);

    if(x1 % x2 == 0 || x2 % x1 == 0 )printf("Sao Multiplos\n");
    else printf("Nao sao Multiplos\n");

    return 0;
}
