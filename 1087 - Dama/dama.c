
#include <stdio.h>

int main() {

    int x1, y1, x2, y2;

    while (1 == 1) {
        scanf("%d %d %d %d", & x1, & y1, & x2, & y2);
        if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
            break;
        int achou = 0;
        if (x1 == x2 && y1 == y2) {
            printf("0\n");
        } else if (x1 == x2 || y1 == y2) {
            printf("1\n");
        } else {
            /*tem diagonal*/
            int i = x1, j = y1, k = x1, l = y1, m = x1, n = y1, o = x1, p = y1;
            while (1 == 1) {
                if (i < 9) {
                    i++;
                }
                if (j < 9) {
                    j++;
                }
                if (k > 0) {
                    k--;
                }
                if (l > 0) {
                    l--;
                }
                if (m < 9) {
                    m++;
                }
                if (n > 0) {
                    n--;
                }
                if (o > 0) {
                    o--;
                }
                if (p < 9) {
                    p++;
                }
                /*printf("i = %d j = %d k = %d l = %d m = %d n = %d o = %d p = %d\n", i, j, k , l, m, n, o, p);*/
                if ((i == 9 || j == 9) && (k == 0 || l == 0) && (m == 9 || n == 0) && (o == 0 || p == 9)) {
                    break;
                }
                if ((i == x2 && j == y2) || (k == x2 && l == y2) || (m == x2 && n == y2) || (o == x2 && p == y2))
                    achou = 1;
            }
            if (achou == 1) {
                printf("1\n");
            } else {
                printf("2\n");
            }
        }

    }
    return 0;
}
