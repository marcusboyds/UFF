import copy

l, c, m, n = list(map(int, input().split()))

#Criar cajueiro
cajueiro = []
for i in range(l):
    cajueiro.append(list(map(int, input().split())))

#Proteger a matriz
linha1 = [0]*(c+1)
cajueiro.insert(0, linha1)

for i in range(1,l+1):
    cajueiro[i].insert(0, 0)
    
cajueiro2 = list(cajueiro)
imagem = [None]*(l+1)
imagem = cajueiro[:]


#Criar imagem integral do cajueiro
for lin in range(1,l+1):
    for col in range(1,c+1):
        imagem[lin][col] = imagem[lin-1][col] + imagem[lin][col-1] - imagem[lin-1][col-1] + cajueiro2[lin][col]

maior_valor = -1

#Definir l1,c1 e l2,c2 pra cada lote
for lin in range(1,l+1):
    for col in range(1,c+1):
        l1, c1, l2, c2 = lin, col, lin+m-1, col+n-1
        if c2 > c:
            c2 = c2 - (c2-c)
        if l2 > l:
            l2 = l2 -(l2-l)
        soma = imagem[l2][c2] - imagem[l1-1][c2] - imagem[l2][c1-1] + imagem[l1-1][c1-1]
        if soma > maior_valor:
           maior_valor = soma

print(maior_valor)