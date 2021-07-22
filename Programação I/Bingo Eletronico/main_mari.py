def select_sort_reverse(lista):
    for i in range(len(lista)): 
        mini = i 
        for j in range(i+1, len(lista)): 
            if lista[mini] < lista[j]: 
                mini = j             
        lista[i], lista[mini] = lista[mini], lista[i]
    return lista

def ordenar_dicionario_desc(dicionario):
    
    tup = list(dicionario.items())
    lst = len(tup)
    for i in range(0,lst): 
        mini = i 
        for j in range(i+1, lst): 
            if tup[mini][1] < tup[j][1]: 
                mini = j             
        tup[i], tup[mini] = tup[mini], tup[i]
    return dict(tup)


def select_sort(lista):
    for i in range(len(lista)): 
        mini = i 
        for j in range(i+1, len(lista)): 
            if lista[mini] > lista[j]: 
                mini = j             
        lista[i], lista[mini] = lista[mini], lista[i]
    return lista

def ordenar_dicionario(dicionario):
    
    tup = list(dicionario.items())
    lst = len(tup)
    for i in range(0,lst): 
        mini = i 
        for j in range(i+1, lst): 
            if tup[mini][1] > tup[j][1]: 
                mini = j             
        tup[i], tup[mini] = tup[mini], tup[i]
    return dict(tup)

def ordenar_cartelas(dicionario):
    
    tup = list(dicionario.items())
    lst = len(tup)
    for i in range(0,lst): 
        mini = i 
        for j in range(i+1, lst): 
            if len(tup[mini][1]) > len(tup[j][1]): 
                mini = j             
        tup[i], tup[mini] = tup[mini], tup[i]
    return dict(tup)


def select_sort_cartela(lista):
    for i in range(len(lista)): 
        mini = i 
        for j in range(i+1, len(lista)): 
            if len(lista[mini]) > len(lista[j]): 
                mini = j             
        lista[i], lista[mini] = lista[mini], lista[i]
    return lista



#Classes locais
import gerador
import leitor
import copy

nCartelas = int(input('Quantas cartelas você deseja no bingo?: '))
gerador.gerarCartela(nCartelas)

#1. Armazenar cartelas geradas no arquivo de texto na variável cartelas abaixo.
cartelas = leitor.lerCartelas()

cartelas = dict([(i+1,cartela) for i, cartela in enumerate(cartelas)])

cartelas_originais = copy.deepcopy(cartelas)

#2. Criar globo de números aleatória a serem sorteados
globo = leitor.gerarGlobo()

#3. Cartelas cujo todos os números foram sorteados.
cartelasCompletas = []

#4. Quantidade de números sorteados em cada cartela
sorteadosPorCartela = [0] * nCartelas

sorteadosPorCartela = dict([(i+1, sort) for i, sort in enumerate(sorteadosPorCartela)])

#5. Numeros que foram retirados do globos
sorteados = []

numero_do_sorteio = 0

#6. Realizar sorteio
while len(cartelasCompletas) == 0:

    # Contador que identifica qual é o número do sorteio 
    sorteado = leitor.sortear(globo)
    sorteados.append(sorteado)

    # Checar nas cartelas se tem o numero sorteado
    for id, cartela in cartelas.items():
        for num in cartela:
            # Caso o número da vez for o sorteado, faça
            if sorteados[numero_do_sorteio] == num:
                # Retirar o número da lista, para evitar iterações maiores
                cartela.pop(cartela.index(num))
                # Somar +1 na lista sorteadosPorCartela, no index referente aquela cartela
                sorteadosPorCartela[id] += 1
        
        # Caso a cartela esteja completa, adicionar o index da cartela a lista de cartelas completas
        if len(cartela) == 0:
            cartelasCompletas.append(id)
        if len(cartela) == 1:
            print(f'A cartela {id} tem 9 números sorteados')
    
    
    print('I- O último número sorteado foi:',sorteados[-1])
    print('II- Os números já sorteados foram:',sorteados,'\n')
    
    # (III) Printar cada valor de sorteadosPorCartela em ordem decrescente, junto ao index da cartela
    print('III - Valores sorteados por cartela',ordenar_dicionario_desc(sorteadosPorCartela))

    print('III - Valores restantes na cartela',ordenar_cartelas(cartelas))


    # lista melhor ideia que tive é criar mais uma lista contendo tambem os index das cartelas (0 à nCartelas-1)
        # E ir ordenando ele junto com a lista sorteadosPorCartela
    for j in range(len(cartelasCompletas)):
        if cartelasCompletas[j] != 0:
            print(f'Cartela {cartelasCompletas[j]}: {cartelas_originais[cartelasCompletas[j]]} números sorteados')
    
    
    # (IV) Caso (10 - len(cartela) == 9), alertar o usuario
    for id, cartela in cartelas.items():
        if len(cartela) == 1:
            print(f'A cartela cartelas[id] teve 9 números sorteados')
        
    numero_do_sorteio += 1
    
    print('\n',numero_do_sorteio,'\n')

# Após encerrar o sorteio
# (V) Printar len(sorteados)
print(f'Quantidade de números sorteados: {len(sorteados)}')
# (VI) Printar sorteados
print(f'Lista de números sorteados: {sorteados}')
# (VII) Printar len(cartelasCompletadas)
print(f'Quantas cartelas foram vencedoras: {cartelasCompletas}')
# (VIII) Printar cartelasCompletadas
for i in range(len(cartelasCompletas)):
    print(f'{i+1}- Quais foram as cartelas vencedoras: {cartelasCompletas[i]}')

