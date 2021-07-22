def buscarMaior(a,b,c):
    maior = o1
    if maior < o2:
        maior = o2
    if maior < o3:
        maior = o3
    return maior

o1, o2, o3 = input().split()
o1 = int(o1)
o2 = int(o2)
o3 = int(o3)

#Achar o maior da lista
lista = [o1,o2,o3]
maior = buscarMaior(o1,o2,o3)

if o1 == o2 == o3 or o1 == o2 or o2 == o3 or o1 == o3:
    print('S')
else:
    if (sum(lista)/2)==maior:
        print ('S')
    else:
        print ('N')