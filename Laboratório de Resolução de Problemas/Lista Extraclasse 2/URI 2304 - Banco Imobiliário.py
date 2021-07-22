inicial, n = input().split()
inicial = int(inicial)
n = int(n)
D = inicial
E = inicial
F = inicial
#Para cada linha, faça
for _ in range(n):
    operacao = input().split() 
    if operacao[0] == 'C': #Operação de compra
        if operacao[1] == 'D':
            D = D - int(operacao[2])
        if operacao[1] == 'E':
            E = E - int(operacao[2])
        if operacao[1] == 'F':
            F = F - int(operacao[2])
    if operacao[0] == 'V': #Operação de venda
        if operacao[1] == 'D':
            D = D + int(operacao[2])
        if operacao[1] == 'E':
            E = E + int(operacao[2])
        if operacao[1] == 'F':
            F = F + int(operacao[2])
    if operacao[0] == 'A': #Operação de alguel
        if operacao[1] == 'D':
            if operacao [2] == 'E':
                D = D + int(operacao[3])
                E = E - int(operacao[3])
            if operacao [2] == 'F':
                D = D + int(operacao[3])
                F = F - int(operacao[3])
        if operacao[1] == 'E':
            if operacao [2] == 'D':
                E = E + int(operacao[3])
                D = D - int(operacao[3])
            if operacao [2] == 'F':
                E = E + int(operacao[3])
                F = F - int(operacao[3])
        if operacao[1] == 'F':
            if operacao [2] == 'D':
                F = F + int(operacao[3])
                D = D - int(operacao[3])
            if operacao [2] == 'E':
                F = F + int(operacao[3])
                E = E - int(operacao[3])
print(D,E,F)

