import random

def gerarCartela(n):
    """ Função que retorna n cartelas com 10 numeros entre 00 e 99, todas distintas. """
    cartelas = []
    i = 0

    # Itera para cada n cartelas definidas
    while i < n:
        aleatorios = []
        x = 0

        # Itera gerando os 10 numeros aleatorios
        while x < 10:
            aleatorio = random.randint(0, 99)
            # Caso o numero aleatorio não exista dentro do vetor aleatorios, atribui este numero ao vetor
            if aleatorio not in aleatorios:
                aleatorios.append(aleatorio)
                x += 1

        # Apartir do final da geração da segunda cartela, verifica se as cartelas geradas não são duplicatas
        if(i > 0):
            if(compararCartela(aleatorios, cartelas) == False):
                cartelas.append(aleatorios)
                i += 1
        else:
            cartelas.append(aleatorios)
            i += 1

    salvarCartela(cartelas)

def salvarCartela(cartelas):
    """ Função que salva a cartela em um arquivo de texto, ordenadas por linha. """
    arqCartelas = open("cartelas.txt", "w")

    for i in range(len(cartelas)):
        arqCartelas.write(' '.join(str(x) for x in cartelas[i]))
        if i < len(cartelas) - 1:
            arqCartelas.write('\n')

    arqCartelas.close()

def compararCartela(cartela, cartelas):
    """ Função que compara uma cartela as cartelas já existentes. Retorna True caso exista alguma igual, 
    e False caso todas sejam diferentes. """
    x = 0
    igual = True
    
    # Itera cada cartela ja gerada pelo sistema
    while x < len(cartelas):
        try:
            # Testa cada numero dentro da cartela gerada, verificando se existe este numero na cartela[x]
            for i in range(10):
                cartelas[x].index(cartela[i])
        # Caso não exista este valor, a cartela já não é uma duplicata
        # Atualiza valor de igual para False
        except ValueError:
            igual = False
            x += 1
        # Caso exista este valor, a cartela pode ser uma duplicata
        # Mantém o valor de igual em True
        else:
            x += 1

        # Ao final da checagem, verifica se todos os numeros são iguais
        # Caso seja, a variavel igual estará com o valor True mantido
        # Sendo uma duplicata, não precisa mais fazer nenhuma outra checagem em outras cartelas
        if(igual == True):
            break

    return igual
