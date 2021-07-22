#Subprogramas

#Função Preencher
def preencher(lista):
    for i in range (len(lista)):
        lista[i] = int(input('Elemento ['+str(i)+'] = '))
    return lista

#Ordenação Simples

def ordena(lista):
    for i in range(len(lista)):
        for j in range(i+1,len(lista)):
            if lista[i] > lista[j]:
                lista[i], lista[j] = lista[j], lista[i]
    return lista

#Conjunto 2 - Selection Sort
#Procura pelo menor número na lista depois do i e troca de posição

#Troca as posições de dois números em uma lista
def troca(lista, posX, posY):
    posicaoX = lista[posX]
    lista[posX] = lista[posY]
    lista[posY] = posicaoX
    return None
#Seleciona o Menor, olha o menor número diante do ínicio dado pelo loop externo    
def selecionarMenor(lista, inicio):
    localMenor = inicio
    for pos in range(inicio+1, len(lista)):
        if lista[pos]<lista[localMenor]:
            localMenor = pos
    return localMenor
#Roda um loop que toma posições de início de uma lista, e da a posição para para a
#função selecionarMenor e logo após troca o início com a menor posição
def selectionSort(lista):
    for i in range(len(lista)-1):
        menor = selecionarMenor(lista, i)
        troca(lista, i, menor)
    return None


#Programa Principal
lista = [0]*10
preencher(lista)
print('Vetor Lido:', lista)
selectionSort(lista)
print('Vetor Ordenado', lista)