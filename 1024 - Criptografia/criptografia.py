qtd = int(input())
indice = 0
while(indice < qtd):
  palavra = input()
  resultado = ""
  meio = int(len(palavra) / 2)
  i = 0
  for j in palavra:
    if(j.isalpha()):
      resultado = (chr(ord(j) + 3)) + resultado
    else:
      resultado = (chr(ord(j))) + resultado
  saida = resultado[:meio]
  for i in range(meio, len(resultado)):
    saida = saida + chr(ord(resultado[i]) -1)
  print(saida)
  indice += 1
