qtd_chocadeiras, qtd_frangos = list(map(int, input().split()))
taxa_de_producao = list(map(int, input().split()))

frangos = []
dia = 1

while len(frangos) < qtd_frangos:
    i = 0
    if dia % taxa_de_producao[i] == 0:
        frangos.append('frango')
        i += 1 
    dia += 1
    
print((dia//2))