#include <stdio.h>

typedef struct node{
	char valor;
	struct node* esquerda;
	struct node* direita;
}Node;

typedef struct{
	Node* head;
}Graph;

int main(){
	
	int qtdNodes;
	
	scanf("%d", &qtdNodes);
	Node nos[qtdNodes];
	
	return 0;
}
