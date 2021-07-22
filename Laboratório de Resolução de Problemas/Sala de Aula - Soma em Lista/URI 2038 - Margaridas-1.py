l, c, m, n = list(map(int, input().split()))

matriz = [None] * l #Alocar na memória a matriz

#Armazenar a matriz dentro de uma matriz
#Para cada linha, leia:
print(matriz)

for _ in range(l):
    #Cada coluna
    matriz.append(list(map(int, input().split())))

print(matriz)


maior_valor = -1

#Entrar nos vetores nulo de cada lote
for linha in range(0, l, m):
    for coluna in range(0, c, n):
        soma_do_lote = 0
        #Somar todos os números no lote e armazernar na soma do lote
        for linha_lote in range(m):
            for coluna_lote in range(n):
                soma_do_lote += matriz[linha+linha_lote][coluna_lote+coluna]
        if soma_do_lote > maior_valor:
            maior_valor = soma_do_lote
    
print(maior_valor)