def minha_chave(arg):
    return len(arg)

n = int(input())

#Para cada n, faça
for _ in range(n):
    strings = input().split()
    strings.sort(reverse=True, key=minha_chave)
    print(' '.join(strings))
        
 