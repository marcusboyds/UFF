def acharMMC(b,d):
    if b > d:
        maior = b
    else:
        maior = d

    while True:
        if maior % b == 0 and maior % d == 0:
            break
        else:
            maior += 1
    return maior

a,b,c,d = input().split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
       
mmc = acharMMC(b,d)
numerador = int((mmc/b*a)+(mmc/d*c))
denominador = mmc
indice = int(denominador)

#Reduzir a fração
#Enquanto


for i in range(denominador):
    if numerador % indice == 0 and denominador % indice == 0: #Se o resto da divisão do denominador pelo numerador for 0
        numerador /= indice
        denominador /= indice
        print (int(numerador),int(denominador))
        break
    else:                      #Senão, diminui 1 do denominador
        indice -= 1
