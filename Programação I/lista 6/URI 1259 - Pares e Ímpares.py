#Retornar tupla, onde o primeiro elemento é a paridade e o ultimo é o proprio elemento
def minha_chave(arg):
    paridade = 0
    if arg % 2 == 0:
        paridade = 0
    else:
        arg = arg*-1
        paridade = 1
    return paridade, arg

n = int(input())

lista = [None]*n

for i in range(n):
    lista[i] = int(input())
    
lista.sort(key=minha_chave)

for i in range(n):
    print(lista[i])