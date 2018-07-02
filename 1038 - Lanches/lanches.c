#include <stdio.h>

int main(){
	
	double valores[] = {0 , 4, 4.5, 5, 2, 1.5}, total;
	
	int v1, v2;
	
	scanf("%d %d",&v1, &v2);
	
	total = valores[v1] * v2;
	
	printf("Total: R$ %2.2lf\n", total);
	
	return 0;
}
