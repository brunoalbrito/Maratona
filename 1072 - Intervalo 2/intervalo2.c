#include <stdio.h>

int main(){
	
	int n, i, valor, in = 0, out = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &valor);
		if(valor >= 10 && valor <= 20){
			in++;	
		}else{
			out++;		
		}
	}
	
	printf("%d in\n", in);
	printf("%d out\n", out);
	
	return 0;
}
