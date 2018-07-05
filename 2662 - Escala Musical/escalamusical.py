qtd = int(input())


entrada = []
notas = {1:"do", 2:"do#" , 3:"re", 4:"re#", 5:"mi",  6:"fa", 7:"fa#", 8:"sol", 9:"sol#", 10:"la", 11:"la#", 12:"si"}
i = 0;
while i < qtd:
	entrada.append(int(input()))
	if(entrada[i] >  12):
		entrada[i] = entrada[i] % 12;
		
	i+= 1

i = 0;
while i < qtd:
	print(notas[entrada[i]] +" "+ str(entrada[i]))
	i += 1
