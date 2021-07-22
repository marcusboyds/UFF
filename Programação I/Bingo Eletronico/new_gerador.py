import random

def gerarCartelas(n):

    cartelas = set()
    # Um set não pode conter elementos identicos, evita todo o processo de comparação

    while len(cartelas) < n:
        # até o comprimento do set chegar até n, loop:

        numeros_disponiveis = list(range(100))
        cartela = tuple(random.sample(numeros_disponiveis, 10))
        # sample exige uma lista pra iterar, então fiz uma lista usando range
        # não da pra fazer set de lista, então converti em tuplas
        cartelas.add(cartela)
    
    return cartelas


exit(0)
