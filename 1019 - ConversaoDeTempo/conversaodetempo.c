#include <stdio.h>

int main(){
	
	float horas, minutos, segundos;
	int tempoinformado;
	
	scanf("%d", &tempoinformado);
	
	horas = tempoinformado / (60 * 60);
	minutos = (tempoinformado - (horas * 60 * 60)) / 60;
	segundos = (tempoinformado % 60);

	
	printf("%0.0f:%d:%0.0f\n",horas, ((int) minutos), segundos);
	
	return 0;
}
