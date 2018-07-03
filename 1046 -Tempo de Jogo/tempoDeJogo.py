entrada = input().split(" ")

a = int(entrada[0])
b = int(entrada[1])


if(b < a or a == b):
    b += 24

resultado = a - b
if(resultado < 0):
  resultado *= -1
print("O JOGO DUROU %d HORA(S)"%resultado)
