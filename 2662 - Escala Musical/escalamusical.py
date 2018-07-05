qtd = int(input())
entrada = []
notas = { 1:"do", 2:"do#", 3:"re", 4:"re#", 5:"mi", 6:"fa", 7:"fa#", 8:"sol", 9:"sol#", 10:"la", 11:"la#", 12:"si" }
escala = { "do":0, "do#":0, "re":0, "re#":0, "mi":0, "fa":0, "fa#":0, "sol":0, "sol#":0, "la":0, "la#":0, "si":0 }
intervalos = { 2, 2, 1, 2, 2, 2, 1 }
tamanhoIntervalo = 7


i = 0;
while (i < qtd):

	entrada.append(int(input()))

	if (entrada[i] >  12):
		entrada[i] = entrada[i] % 12;

	if (i == 0):
		indiceNota = entrada[i]
		escala[notas[indiceNota]] = intervalos[0]
		j = 1

		while (j < tamanhoIntervalo):
			indiceProximaNota = indiceNota + intervalos[i-1]

			if (indiceProximaNota > 12):
				indiceProximaNota = indiceProximaNota % 12

			escala[notas[indiceProximaNota]] = intervalos[0]

	i+= 1

i = 0;
while i < qtd:
	print(notas[entrada[i]] +" "+ str(entrada[i]))
	i += 1
