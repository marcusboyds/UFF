import ast

def minha_chave(arg):
    return -arg[1], -arg[2], -arg[3], arg[0]

def converter(l):
    try:
        return ast.literal_eval(l)
    except ValueError:
        return l

n = int(input())

paises = [None]*n #Alocar lista na memoria, no tamanho de n

#Dar entrada da lista de paises
for i in range(n):
    paises[i] = list(map(converter, input().split()))

paises.sort(key=minha_chave)

for i in range(n):
    print(' '.join(map(str, paises[i])))