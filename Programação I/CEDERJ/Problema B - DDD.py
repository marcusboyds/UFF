def buscaElemento(procurado,lista):
    for i in range(len(lista)):
        if procurado==lista[i]:
            return i
    return -1
            
n = int(input())


lista = ['Brasilia','Salvador','Sao Paulo',
         'Rio de Janeiro','Juiz de Fora','Campinas',
         'Vitoria','Belo Horizonte']

ddd = [61,71,11,21,32,19,27,31]

i = buscaElemento(n,ddd)
if i == -1:
    print('DDD nao cadastrado')
else:
    print(lista[i])
