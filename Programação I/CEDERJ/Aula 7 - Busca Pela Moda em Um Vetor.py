'''
#######################################################
#                                                     #  
&         Aula 6 - Busca pela moda em um vetor        &
#                                                     #
#######################################################
#                     Algorítmo                       #
#                                                     #
$  Preencher uma lista vazia e buscar a moda da lista $
$      números que se mais se repetem em um vetor.    $
#                                                     #
#                                                     # 
#######################################################
'''
#Subprogramas

def preencher(lista):
    for i in range (len(lista)):
        lista[i] = int(input('Elemento ['+str(i)+'] = '))
    return lista

def buscarModa(lista):
    auxiliar = [0]*len(lista) #criar lista auxiliar vazia no tamanho da lista principal
    for i in range(len(lista)):
        auxiliar[i] = 1
        for varre in range (i+1, len(lista)):       #Calcular as frequênicas
            if lista[i]==lista[varre]:
                auxiliar[i]+= 1
    ondeModa=0
    for i in range (1,len(lista)):
        if auxiliar[i] > auxiliar[ondeModa]:
            ondeModa = i
    return lista[ondeModa]

def buscarModaOrdenada(lista):
    moda = lista[0]
    ind = 0
    frequencia = 1
    while ind < len(lista)-1:
        ind = ind+1
        if lista[ind] == lista[ind-frequencia]:
            moda = lista[ind]
            frequencia += 1
    return moda
            
#Programa Principal
lista = [0]*10
preencher(lista)
moda = buscarModaOrdenada(lista)

print('A moda do vetor é {}'.format(moda))

