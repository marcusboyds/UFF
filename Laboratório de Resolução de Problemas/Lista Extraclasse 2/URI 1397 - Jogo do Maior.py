n = int(input())
while n != 0:
    jogador_a = 0
    jogador_b = 0
    for i in range(n):
        a, b = input().split()
        if int(a) > int(b):
            jogador_a += 1
        elif int(a) < int(b):
            jogador_b += 1
        elif int(a) == int(b):
            jogador_a += 0
            jogador_b += 0
        
    print(jogador_a, jogador_b)
    n = int(input())       
        