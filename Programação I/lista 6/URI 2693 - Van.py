import ast

def converter(l):
    try:
        return ast.literal_eval(l)
    except ValueError:
        return l

def minha_chave(arg):
    return arg[2], arg[1], arg[0]
    
while True:
    try:
        n = int(input())
        
        alunos = [None]*n

        for i in range(n):
            alunos[i] = list(map(converter, input().split()))
            
        alunos.sort(key=minha_chave)

        for i in range(n):
            print(alunos[i][0])
    except EOFError:
        break
   
