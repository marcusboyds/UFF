lista = input().split()
lista = list(map(int, lista))

contador_crescente = 0
contador_decrescente = 0

#Percorrer pares de item e avaliar se são crescentes ou decrescentes
for i in range(len(lista)-1):
    #Avalia se é decrescente
    if lista[i] >= lista[i+1]:
        contador_decrescente += 1
    #Avalia se é crescente
    elif lista[i] <= lista[i+1]:
        contador_crescente += 1
    
#Analisar se os contadores apontam pra ordem decrescente, crescente ou fora de ordem
if contador_decrescente == len(lista)-1:
            print('D')
elif contador_crescente == len(lista)-1:
            print('C')
else:
    print('N')
    