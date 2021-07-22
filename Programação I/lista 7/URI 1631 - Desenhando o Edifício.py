def minha_chave(arg):
    return abs(arg)

p = int(input())
#Para cada p conjuto de teste, faça
for _ in range(p):
    #Quantidade de pisos
    n = int(input())
    
    #Inserir pisos
    pisos = [None]*n
    for i in range(n):
        pisos[i] = int(input())
    
    #Classificar e ordenar a lista
    pisos.sort(reverse=True, key=minha_chave)
    for i in range(n):
        if pisos[i] > 0:
            pisos[i] = 0
        else:
            pisos[i] = 1
    pisos.insert(0, 2)
    #Verificar se o anterior é diferente, se sim soma 1
    andares = 0
    for i in range(1,n):
        if pisos[i] != pisos[i-1]:
            andares += 1
    print(andares)