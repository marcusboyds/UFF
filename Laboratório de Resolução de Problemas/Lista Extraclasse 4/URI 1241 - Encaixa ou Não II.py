n = int(input())

for _ in range(n):
    AeB = input().split()
    A = AeB[0]
    B = AeB[1]
    if A[-len(B):] == B:
        print('encaixa')
    else:
        print('nao encaixa')