palavras = []

palavras = (input().upper()).split(" ")

while(palavras[0] != "*"):
  anterior = palavras[0][0]
  tautogramas = True
  for i in palavras:
    if(i[0] == anterior):
      tautogramas = True
      anterior = i[0]
    else:
      tautogramas = False
      break

  if(tautogramas):
    print("Y")
  else:
    print("N")
  
  palavras = (input().upper()).split(" ")


