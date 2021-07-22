n = int(input())
t = 1
while n != 0:
    print (f'Teste {t}')
    lista = input().split()
    lista = list(map(int, lista))
    for i in range(n):
         if lista[i] == i+1:
            print(lista[i])
    print ()
    n = int(input())
    t += 1