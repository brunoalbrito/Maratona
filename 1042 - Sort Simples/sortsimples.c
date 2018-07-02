#include <stdio.h>


int main(){
	int a, b, c;
	int auxa, auxb, auxc, aux;
	
	scanf("%d %d %d", &a, &b, &c);
	auxa = a;
	auxb = b;
	auxc = c;
	
	if(a > b){
		aux = b;
		b = a;
		a = aux;
	}
	if(b > c){
		aux = b;
		b = c;
		c = aux;
	}if(a > b){
		aux = b;
		b = a;
		a = aux;
	}
	
	printf("%d\n%d\n%d\n\n", a,b,c);
	printf("%d\n%d\n%d\n", auxa,auxb,auxc);
	
	return 0;
}
