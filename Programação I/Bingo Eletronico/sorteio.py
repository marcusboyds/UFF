import random
import new_gerador

# aqui a entrada seria um conjunto de arquivos de texto, gerados pelo gerador. usei a função na marra pra testar

test = new_gerador.gerarcartelas(50)

# a função retorna um conjunto, então precisei converter em uma lista de listas (vetor de vetores)

cartelas_convertidas = []

for element in test:
    l = list(element)
    cartelas_convertidas.append(l)

# declarei aqui o que cada sorteio deve usar

globo = list(range(100))
completas = []
sorteados = []

# enquanto a lista de completas estiver vazia, loop:

while len(completas) == 0:
    s = random.choice(globo)
    globo.remove(s)
    sorteados.append(s)

    # dessa vez eu usei uma função que retorna um escalar (a sample retorna uma lista)
    # agora, pra cada cartela no conjunto que criei:

    for cartela in cartelas_convertidas:

        # transformei os bgl em conjunto, pra poder comparar de forma booleana

        cartela_ordenada = set(cartela)
        sorteado_ordenado = set(sorteados)

        if cartela_ordenada.issubset(sorteado_ordenado):
            completas.append(cartela)

            # .issubset retorna positivo se os dois sets forem iguais (independente da ordem)
            # se der True, a cartela que tá sendo avaliada é adicionada à lista de completas

print(completas)

# isso aqui foi só pra testar se tava funcionando

# em suma, isso aqui é a estrutura que a função de sorteio tem que ter, em hard coding
# agora que a gente sabe que funciona, precisamos transformar em função e construir uma main

exit(0)
