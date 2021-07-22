l = int(input())
c = int(input())
#se a quantidade de linhas for igual a quantidade de colunas
if l == c:
    #imprima 1
    print (1)
#se a quantidade de lados e de colunas for impar 
elif l % 2 == 1 and c % 2 == 1:
    #imprima 1
    print (1)
#se a quantidade de lados e de colunas for par 
elif l % 2 == 0 and c % 2 == 0:
    #imprima 1
    print (1)
#se a quantidade de lados e de colunas de paridade diferente
elif l % 2 == 1 and c % 2 == 0:
    print (0)
elif l % 2 == 0 and c % 2 == 1:
    print (0)