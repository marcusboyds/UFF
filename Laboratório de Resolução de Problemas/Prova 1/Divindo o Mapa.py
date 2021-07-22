import math

n = int(input())
t = 1
while n != -1:
    print(f'Teste {t}')
    print((math.log2(4*2*n)**2))
    t += 1
    n = int(input())
