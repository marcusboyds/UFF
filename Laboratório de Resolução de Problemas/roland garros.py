jogadores = int(input())
f = [jogadores]
while jogadores != 1:
    jogadores = jogadores // 2
    f.append(jogadores)
rodadas = len(f) -1
print(rodadas)
partidas = 0
for i in range(rodadas):
    partidas = int(partidas + f[i])
print(partidas/2)
