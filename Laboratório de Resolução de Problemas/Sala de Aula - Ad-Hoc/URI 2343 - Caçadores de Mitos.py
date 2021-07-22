#Algoritmo: olhar uma lista de tuplas, se tiver um par igual, imprimir 1, senão imprimir 0

def verificar(lista):
    for i in range (len(lista)):
        for j in range(i+1,len(lista)):
            if lista[i][0] == lista[j][0] and lista[i][1] == lista[j][1]:
                print(1)
                break
            else:
                print(0)
                break
coordenadas = []

n = int(input())
for i in range (n):
    coordenadas.append(input().split())

verificar(coordenadas)


    