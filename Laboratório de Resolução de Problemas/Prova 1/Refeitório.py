def buscarRefeitorio(a,b,c):
    if a == b == c or b == c or c == b or a == b or a == c:
        refeitorio = b
    else:
        maior = a
        if (b > maior):
            maior = b
        if (c > maior):
            maior = c
        refeitorio = maior
    return refeitorio

def totalGasto(refeitorio):
    if refeitorio == b:
        print ((a*2)+(c*2))
    elif refeitorio == a:
        print ((b*2)+(c*4))
    elif refeitorio == c:
        print ((a*4)+(b*2))

a = int(input())
b = int(input())
c = int(input())

lista = [a,b,c]

refeitorio = buscarRefeitorio(a,b,c)
totalGasto(refeitorio)
    