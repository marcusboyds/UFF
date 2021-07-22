a, b, c = map(float, input().split())
#definir o angulo e se forma triangulo
if(a >= b) and (a >= c):
  calculo1 = b + c
  if(a >= calculo1):
    print('NAO FORMA TRIANGULO')
  else:
    cálculo2 = (b ** 2) + (c ** 2)
    if(a ** 2 == calculo2):
      print('TRIANGULO RETANGULO')
    elif(a ** 2 > calculo2):
      print('TRIANGULO OBTUSANGULO')
    else:
      print('TRIANGULO ACUTANGULO')
elif(b >= a) and (b >= c):
  calculo1 = a + c
  if(b >= calculo1):
    print('NAO FORMA TRIANGULO')
  else:
    calculo2 = (a ** 2) + (c ** 2)
    if(b ** 2 == calculo2):
      print('TRIANGULO RETANGULO')
    elif(b ** 2 > calculo2):
      print('TRIANGULO OBTUSANGULO')
    else:
      print('TRIANGULO ACUTANGULO')
elif(c >= a) and (c >= b):
  calculo1 = b + a
  if(c >= calculo1):
    print('NAO FORMA TRIANGULO')
  else:
    calculo2 = (b ** 2) + (a ** 2)
    if(c ** 2 == calculo2):
      print('TRIANGULO RETANGULO')
    elif(c ** 2 > calculo2):
      print('TRIANGULO OBTUSANGULO')
    else:
      print('TRIANGULO ACUTANGULO')
#definir propriedade dos lados
if(a == b) and (b == c):
  print('TRIANGULO EQUILATERO')
elif(a == b) or (b == c) or (c == a):
  print('TRIANGULO ISOSCELES')