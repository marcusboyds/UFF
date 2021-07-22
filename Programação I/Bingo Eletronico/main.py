def select_sort_reverse(lista):
    for i in range(len(lista)): 
        mini = i 
        for j in range(i+1, len(lista)): 
            if lista[mini] < lista[j]: 
                mini = j             
        lista[i], lista[mini] = lista[mini], lista[i]
    return lista

def select_sort(lista):
    for i in range(len(lista)): 
        mini = i 
        for j in range(i+1, len(lista)): 
            if lista[mini] > lista[j]: 
                mini = j             
        lista[i], lista[mini] = lista[mini], lista[i]
    return lista

import gerador
import leitor

nCartelas = int(input('Quantas cartelas você deseja no bingo?: '))
gerador.gerarCartela(nCartelas)

#1. Armazenar cartelas geradas no arquivo de texto na variável cartelas abaixo.
cartelas = leitor.lerCartelas()

#2. Criar globo de números aleatória a serem sorteados
globo = leitor.gerarGlobo()

#3. Cartelas cujo todos os números foram sorteados.
cartelasCompletas = []

#4. Quantidade de números sorteados em cada cartela
sorteadosPorCartela = [0] * nCartelas

#5. Numeros que foram retirados do globos
sorteados = []

#6. Realizar sorteio
while len(cartelasCompletas) == 0 or len(globo)==0:

    # Contador que identifica qual é o número do sorteio 
    numero_do_sorteio = 0
    while len(globo) != 0:
        sorteado = leitor.sortear(globo)
        sorteados.append(sorteado)

    # Checar nas cartelas se tem o numero sorteado
    for cartela in cartelas:
        for i in range(len(cartela)):
            # Caso o número da vez for o sorteado, faça
            if sorteados[numero_do_sorteio] == cartela[i]:
                # Retirar o número da lista, para evitar iterações maiores
                cartela.pop(i)
                # Somar +1 na lista sorteadosPorCartela, no index referente aquela cartela
                cartelas[cartelas.index(cartela)].append(1)
        # Caso a cartela esteja completa, adicionar o index da cartela a lista de cartelas completas
        if len(cartela) == 0:
            cartelasCompletas.append(cartelas.index(cartela))
        if len(cartela) == 1:
            print(f'A cartela {cartelas.index(cartela)} tem 9 números sorteado')

    
    # (III) Printar cada valor de sorteadosPorCartela em ordem decrescente, junto ao index da cartela
    select_sort_reverse(sorteadosPorCartela)
    select_sort(cartelas)
        # lista melhor ideia que tive é criar mais uma lista contendo tambem os index das cartelas (0 à nCartelas-1)
        # E ir ordenando ele junto com a lista sorteadosPorCartela
    for j in range(len(cartelasCompletas)):
        if cartelasCompletas[j] != 0:
            print(f'Cartela {j}: {cartelasCompletas[j]} números sorteados')
    # (IV) Caso (10 - len(cartela) == 9), alertar o usuario
    
    numero_do_sorteio += 1

# Após encerrar o sorteio
# (V) Printar len(sorteados)
# (VI) Printar sorteados
# (VII) Printar len(cartelasCompletadas)
# (VIII) Printar cartelasCompletadas
