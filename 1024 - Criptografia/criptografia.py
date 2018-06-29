qtd = int(input())
i = 0
while(i < qtd):
  palavra = input()
  resultado = []
  k = 0
  for j in palavra:
    resultado.append(ord(j) + 3)
    k += 1
  saida = ""
  for j in resultado:
    saida = saida + (chr(j))
  print(saida)
  i += 1
