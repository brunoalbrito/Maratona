#include <stdio.h>

int main(){
	
	int datas[] = {365, 30};
	int dataEntrada = 0;
	int ano, mes, dia;
	
	scanf("%d", &dataEntrada);
	
	ano = dataEntrada / datas[0];
	
	mes =  (dataEntrada - (datas[0] * ano)) / datas[1];
	
	dia = (dataEntrada - (datas[0] * ano)) - (datas[1] * mes);
	
	printf("%d ano(s)\n", ano);	
	printf("%d mes(es)\n", mes);
	printf("%d dia(s)\n", dia);
	
	
	return 0;
}
