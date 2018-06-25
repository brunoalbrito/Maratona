#include <stdio.h>

int
main(void)
{
    unsigned int a, b, mofiz;

    while(scanf("%u %u", &a, &b) != EOF) {
        mofiz = a ^ b;
        printf("%u\n", mofiz);
    }

    return 0;
}
