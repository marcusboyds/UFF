def rotate(l, n):
    return l[n:] + l[:n]

palavra = input()
chave = input()
delta = (len(palavra)-len(chave))

#Criar matriz onde cada linha tenha o mesmo tamanho
matriz = [palavra, chave.ljust(delta+len(chave))]
#Fazer espaçamento pra cada chave até a ultima chave estar na mesma posição da palavra
for i in range(1, (delta+1)):
    gigi = chave.ljust(delta+len(chave))
    matriz.append(rotate(gigi, i*-1))

qtd_de_posicoes = len(matriz)-1

for lin in range(1, len(matriz)):
    c = 0
    for col in range(len(palavra)):
        if matriz[lin][col] == palavra[col]:
            c += 1
    if c >= 1:
       qtd_de_posicoes -= 1
       
print(qtd_de_posicoes)
