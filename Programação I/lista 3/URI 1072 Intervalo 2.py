n = int(input())
lista = []
dentro = 0
fora = 0
for i in range (n):
   lista.append(int(input()))  
for i in range(n):
        if 10 <= lista[i] <= 20:
            dentro += 1
        else:
            fora += 1
print(f'{dentro} in')
print(f'{fora} out')
