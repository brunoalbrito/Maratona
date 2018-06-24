#include <stdio.h>
#include <math.h>

void iniciaVetor(int *v){
	int i;
	for(i = 0; i < 32; i++){
		v[i] = 0;
	}
}

void converteBinario(int entrada, int posicao, int vetor[]){
	if(entrada == 0 || entrada == 1){
		vetor[posicao] = entrada;
		return;
	}
	int result = (entrada % 2);
	vetor[posicao] = result;
	return converteBinario(entrada/2, posicao = (posicao + 1), vetor);
}


int convertToDecimal(int *v){
	int i = 0, result = 0;	
	for(i; i < 32; i++){
		result += v[i] * pow(2 , i);
	}
	return result;
}

int main()
{
	int n, m, c, k;
	int a[32];
  	int b[32];
  	int result[32];
  	iniciaVetor(a);
  	iniciaVetor(b);
  	iniciaVetor(result);

	scanf("%d %d", &n, &m);
	  
	  
	converteBinario(n, 0, a);
	converteBinario(m, 0, b);
	
	for (c = 0; c < 32; c++){
	    if(a[c] + b[c] == 0){
	    	result[c] = 0;
		}else if(a[c] + b[c] == 1){
			result[c] = 1;	
		}else{
			result[c] = 0;	
		}
	}
	  
	
	  printf("%d\n", convertToDecimal(result));

  return 0;
}