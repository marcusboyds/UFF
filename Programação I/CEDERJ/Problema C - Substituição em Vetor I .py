#Algoritmo: Fazer um programa que le uma lista, e trocar os valores nulos e negativos da lista para 1

def substituir_nulos_e_negativos(lista):
    for i in range(len(lista)):
        if lista[i] <= 0:
            print('X[',i,'] =',1)
        else:
            print('X[',i,'] =',lista[i])
    
lista = []

for _ in range(10):
    piru = int(input())
    lista.append(piru)
substituir_nulos_e_negativos(lista)