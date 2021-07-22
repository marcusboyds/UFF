def somar(lista):
    soma = 0
    for i in range(len(lista)):
        soma += lista[i]
    return soma

l, c = input().split()
l = int(l)
c = int(c)

matriz = []

for _ in range(l):
    matriz.append(list(map(int, input().split())))
    
maior_colheita = -1

#Verificar a maior colheita horizontalmente
for i in range(l):
    soma_da_linha = somar(matriz[i])
    if soma_da_linha > maior_colheita:
        maior_colheita = soma_da_linha

#Verificar a maior colheita horizontalmente

for col in range(c):
    soma_da_coluna = 0
    for lin in range(l):
        soma_da_coluna += matriz[lin][col]
    if soma_da_coluna > maior_colheita:
        maior_colheita = soma_da_coluna

print(maior_colheita)    
