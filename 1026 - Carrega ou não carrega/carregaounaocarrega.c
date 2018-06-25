#include <stdio.h>

void iniciarVetor(int *v){
	int i;
	for (i = 0; i < 32; i++){
		v[i] = 0;
	}
}

double _pow(double base, double expoente) {
	if (expoente == 0) { return 1; }
	double result = base;
	while (expoente > 1) {
		result = result * base;
		expoente--;
	}
	return result;
}

void toBinario(int entrada, int posicao, int vetor[]){
	if(entrada == 0 || entrada == 1){
		vetor[posicao] = entrada;
		return;
	}
	int result = (entrada % 2);
	vetor[posicao] = result;
	toBinario(entrada/2, posicao = (posicao + 1), vetor);
}


int toDecimanl(int *v){
	int i, result = 0;
	for(i = 0; i < 32; i++){
		result += v[i] * _pow(2 , i);
	}
	return result;
}

void printVetor(int vetor[], int tamanho) {
	int i;
	printf("\n[ ");
	for (i = 0; i < tamanho; i++) {
		printf("%d ", vetor[i]);
	}
	printf("]\n");
}

int main() {
	int n, m, c, k;
	int a[32];
  	int b[32];
  	int result[32];
  	iniciarVetor(a);
  	iniciarVetor(b);
  	iniciarVetor(result);

	while (scanf("%d %d", &n, &m) != EOF) {
		toBinario(n, 0, a);
		toBinario(m, 0, b);

		// printVetor(a, 32);
		// printVetor(b, 32);

		for (c = 0; c < 32; c++) {
			// REALIZANDO OPERAÇÃO X OR (SE VALORES IGUAIS = 0, SE VALORES DIFERENTES = 1)
		    if (a[c] == b[c]) {
		    	result[c] = 0;
			} else {
				result[c] = 1;
			}
		}

		// printVetor(result, 32);

		printf("%d\n", toDecimanl(result));
	}

 	return 0;
}
