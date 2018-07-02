#include <stdio.h>


int main(){
	double n1, n2, n3, n4, exame, media;
	
	scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
	
	media = ((n1 * 0.2) + (n2 * 0.3) + (n3 * 0.4) + (n4 * 0.1));
	printf("Media: %1.1lf\n", media);
	
	if(media > 7){
		printf("Aluno aprovado.\n");
	}else if(media >= 5){
		printf("Aluno em exame.\n");
		scanf("%lf", &exame);
		printf("Nota do exame: %2.1lf\n", exame);
		media = (media + exame) / 2;
		if(media >= 5){
			printf("Aluno aprovado.\n");
			printf("Media final: %2.1lf\n", media);
		}else{
			printf("Aluno reprovado.\n");
			printf("Media final: %2.1lf\n", media);
		}
	}else{
		printf("Aluno reprovado.\n");
	}
	
	return 0;
}
