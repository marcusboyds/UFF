#Sub-programas



def contarNaoTroca(nova, m):
    #Ordernar a lista original como nova
    for i in range (len(nova)):
        for j in range(i, len(nova)):
            if nova[i]<nova[j]:
                nova[i], nova[j] = nova[j], nova[i]
    return nova
    #Comparar quais elementos não mudaram entre a ordenação
def comparar(original, ordenada):
    c = 0
    for i in range(m):
        if ordenada[i] == original[i]:
            c += 1
    print(c)
    return None

#Programa Principal

n = int(input())

#Para N vezes, faça
for _ in range(n):
    m = int(input())
    fila = list(map(int, input().split()))
    copia = fila.copy()
    ordenada = contarNaoTroca(fila, m)
    comparar(copia, ordenada)