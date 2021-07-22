import ast

def converter(l):
    try:
        return ast.literal_eval(l)
    except ValueError:
        return l

def minha_chave(arg):
    return -arg[1], arg[2], arg[3], arg[0]

t = int(input())

for i in range(t):
    n, m = list(map(int, input().split()))
    
    #Entrada de Renas
    renas = [None]*n
    for j in range(n):
        renas[j] = list(map(converter, input().split()))
        
    #Ordenação de Renas
    renas.sort(key=minha_chave)
    
    #Impressão das Renas Escolhidas
    cenario = i+1
    print('CENARIO {'+str(cenario)+'}')
    for k in range(m):
        print(f'{k+1} -',renas[k][0])