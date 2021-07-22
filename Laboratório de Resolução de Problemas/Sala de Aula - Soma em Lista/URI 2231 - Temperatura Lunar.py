#Algoritmo: Criar uma lista acumulada com a entrada e fazer uma operação de i em i elementos

#Sub-programas

#Programa Principal

n, m = list(map(int, input().split()))
t = 1


while n !=0 and n != 0:
    print (f'Teste {t}')
    
    #Criar lista de temperaturas do teste
    lista = []
    for _ in range(n):
        lista.append(int(input()))
    
    #Criar lista acumulada de temperaturas do teste
    lista_acumulada = [None]*n
    for i in range(n):
        if i != 0:
             lista_acumulada[i] = lista_acumulada[i-1] + lista[i]
        else:
            lista_acumulada[i] = lista[i]
            
    min_soma = max_soma = lista_acumulada[m - 1]
    for j in range(m, n):
        soma = lista_acumulada[j] - lista_acumulada[j-m]
        min_soma = min(soma, min_soma)
        max_soma = max(soma, max_soma)
    
    print('%d %d' % (int(min_soma / m), int(max_soma / m)))

    t += 1
    n, m = list(map(int, input().split()))
        