'''
#######################################################
#                                                     #  
&                 URI 2426 - CARTAS                   &
#                                                     #
#######################################################
#                     Algorítmo                       #
#                                                     #
$ Contar o numero das cartas em sequencia e olhar se  $
$        a sequencia é crescente, descrescente        $
#                   ou desordenada                    #
#                                                     # 
#######################################################
'''
                                                    
lista = input().split()
lista = list(map(int, lista))
c1 = 0

'''
#############################################################################################                

Ver se --->[1]--->[3]--->[2] é uma sequência de cartas FORA DE ORDEM (SIM ESTÁ FORA DE ORDEM)
           nº0    nº1    nº2
            
##############################################################################################
                            |||
                            |||
                            VVV
                            '''

if lista[0] > lista[1] and lista[1] < lista[2]:
    print ('N')
elif lista[0] < lista[1] and lista[1] > lista[2]:
    print ('N')

'''
#############################################################################################                

Ver se --->[1]--->[2]--->[3] é uma sequência de cartas CRESCENTE ou DESCRESCENTE (SIM ESTÁ CRESCENTE)
           nº0    nº1    nº2
            
##############################################################################################
                            |||
                            |||
                            VVV
                            '''
for i in range(len(lista)-1):
    #Se o atual for maior que o proximo
    if lista[i]>lista[i+1]:
        #Adicionar 1 no contador c1
        c1 += 1
        #Se c1 for do tamanho da lista
        if c1 == len(lista)-1:
            #Imprima D
            print ('D')
    else:
        c1 += 1
        if c1 == len(lista)-1:
            print ('C')
'''            
@@###################################################@@
@                        Bugs                         @
# Bug 1                                               #
# Programa Atual                                      #
# Entrada: 1 4 2 3 / Saida: N\nC                      #
#                                                     #
#                                                     #
# Programa Ideal                                      #
# Entrada: 1 4 2 3 / Saida: N                         #
#                                                     #
# Motivo: O programa nao finaliza quando a condição N #
# é validada                                          #
# Solução em alto nível: Comparar a maioridade entre o#
# elemento [0] e [1], e entre [1] e [2], se forem     #
#diferentes, imprime N (não ordenado) e finaliza o    #
# programa                                            #
#                                                     #
@                                                     @ 
@@###################################################@@
'''