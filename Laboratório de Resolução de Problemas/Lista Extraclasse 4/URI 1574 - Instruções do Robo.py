def buscarInstrucao(instrucao):
    if len(instrucao) == 3:
        direcao = buscarInstrucao(instrucoes[int(instrucao[2])-1])
    else:
        if instrucao == ['LEFT']:
            direcao = 'LEFT'
        else:
            direcao = 'RIGHT'
    return direcao

def executarInstrucao(instrucao):
    c = 0
    if direcao == 'LEFT':
        c -= 1
    else:
        c += 1
    return c
     
#Quantidade de testes
n = int(input())

#Para cada caso de teste faça
for i in range(n):

    instrucoes = [] 
            
    #Adicionar instruções em uma lista 
    #de instruções
    p = int(input())
    for i in range(p):
        instrucoes.append(input().split())
    
    c = 0

    for instrucao in instrucoes:
        direcao = buscarInstrucao(instrucao)
        c += executarInstrucao(direcao)
    
    print(c)
