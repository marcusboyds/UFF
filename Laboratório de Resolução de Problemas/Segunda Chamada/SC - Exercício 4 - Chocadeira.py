chocadeiras, frangos_desejados = list(map(int, input().split()))

producao = list(map(int, input().split()))

frangos_chocados = 0
dias = 0

#Enquanto a quantidade de frangos chocados for menor o
while frangos_chocados < frangos_desejados and  frangos_chocados != frangos_desejados:
    dias += 1
    #Chocar frango no dia
    for chocadeira in producao:
        if dias % chocadeira == 0:
            frangos_chocados += 1
    if frangos_chocados == frangos_desejados: break
print(dias)

            