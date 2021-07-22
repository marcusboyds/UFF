LETRAS = ('A', 'B', 'C', 'D', 'E')

t = 1
n = int(input())
while n != 0:
    print(f'Teste {t}')

    # Criar a estrutura que guarda a informação de cada dígito de senha
    digitos_provaveis = [list(), list(), list(), list(), list(), list()]

    # Para cada entrada de senha feita pelo usuário faça
    for _ in range(n):
        # Associar cada par de numero a uma letra de A a E
        linha = input().split()
        pares = [(int(linha[0]), int(linha[1])),
                 (int(linha[2]), int(linha[3])),
                 (int(linha[4]), int(linha[5])),
                 (int(linha[6]), int(linha[7])),
                 (int(linha[8]), int(linha[9]))]

        # Para cada letra informada, faça
        letras = linha[10:]
        for i in range(6):
            # Armazene o par de números associados com a letra informada
            indice_do_par = LETRAS.index(letras[i])
            par = pares[indice_do_par]
            digitos_provaveis[i].append(par[0])
            digitos_provaveis[i].append(par[1])

    # Reporta qual número mais apareceu por dígito da senha
    for digito in range(6):
        if digitos_provaveis[digito].count(digitos_provaveis[digito][0]) == n:
            print(digitos_provaveis[digito][0], end=' ')
        elif digitos_provaveis[digito].count(digitos_provaveis[digito][1]) == n:
            print(digitos_provaveis[digito][1], end=' ')

    print('')
    print('')

    t += 1
    n = int(input())
    