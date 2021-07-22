import random
from random import randint

def lerCartelas():
    '''Função que retorna cada cartela do arquivo de texto em uma unica lista'''
    cartelas = []
    arqCartelas = open('cartelas.txt','r')
    
    #Para cada linha no arquivo de texto, adicione como numero inteiro na lista cartelas
    for linha in arqCartelas:
        cartelas.append(list(map(int, linha.split())))
        
    return cartelas

def sortear(globo):
    '''Função que retira um número do globo e armazena na lista de numeros sorteados'''
    sorteado = globo[0]
    del(globo[0])
    
    return sorteado

def gerarGlobo():
    '''Função que gera um novo globo com as bolas já misturadas'''
    globo = []
    for i in range(99):
        globo.append(i)    
    random.shuffle(globo)

    return globo

