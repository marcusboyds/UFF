#Algoritmo: Olhar uma lista, dividir ela em quantidade de turnos. Após se parar as listas, olhar os indicies cujo a soma é a maior
#de todas, caso haja uma soma igual, declarar empate.
def separar(lista, n):
    inicio = 0
    for i in range(n):
        final = inicio + len(lista[i::n])
        yield lista[inicio:final]
        inicio = final
    return lista

def buscarMaior(lista):
    maior = 0
    for i in range (len(lista)):
        if lista[i]>=lista[maior]:
            maior = i
    
    print(maior+1)
            

n, turnos = input().split()

n = int(n)
turnos = int(turnos)

partida = input().split()
partida = list(map(int, partida))

lista = list(separar(partida, turnos))

#Olhar cada lista dentro da lista

auxiliar = [0]*n

for i in range (turnos):
    for j in range(n):
        if lista[i][j] == max(lista[i]):
            auxiliar[j] += 1

buscarMaior(auxiliar)