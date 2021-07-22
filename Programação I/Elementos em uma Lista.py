'''
#######################################################
#                                                     #  
&                  Busca e Procura                    &
#                                                     #
#######################################################
#                     Algorítmo                       #
#                                                     #
$ Adiciona em uma lista vazia de tamanho 10, 10 núme  $
$        ros. E busca a posicao do número desejado    $
#                   nessa lista                       #
#                                                     # 
#######################################################
'''

#Subprogramas

def buscarElemento(valor, numeros):
    for i in range (len(numeros)):
        piru = -1
        if valor == numeros[i]:
            piru = int(i)
            return piru 

def preencher(valores):
    for i in range(len(valores)):
        valores[i] = int(input('Posição ['+str(i)+'] = '))
    return None

def escreverResposta(valor, posicao):
    if posicao < 0:
        print (valor, 'não foi encontrado na posição', posicao)
    else:
        print (valor, 'foi encontrado na posição', posicao)
    return None

#Programa Principal
numeros = [0]*10
valor = int(input('Digite aqui o valor a ser procurado: '))
preencher(numeros)
posicao = buscarElemento(valor, numeros)
escreverResposta(valor, posicao)



