#SUBS
def criarDatabase(nm):
    dicionario = {}
    dados = open(nm,"r",encoding="utf-8")
    for linha in dados:
        j = linha.strip("\n")
        x = [s for s in j.split("#")]
        dicionario[x[0]] = [float(x[1]),int(x[2]),int(x[3])]
    dados.close()
    return dicionario

def mostrar(produtos):
    print('Lendo produtos...')
    for key in produtos.keys():
        print(f'Código {key}: Preço = {produtos[key][0]} Quantidade = {produtos[key][1]}, Dias restantes de validade = {produtos[key][2]}')
        print('=' * (len(f'Código {key}: Preço = {produtos[key][0]} Quantidade = {produtos[key][1]}, Dias restantes de validade = {produtos[key][2]}')))
    print()

def produtosVencendo(produtos):
    print('Esses produtos irão vencer em menos de uma semana: ')
    for k, v in produtos.items():
        if v[2] < 7:
            print(f'Produto {k}')
    return None

def buscaProduto(nm_cliente, produtos):
    pedidos = open(nm_cliente, 'r')
    for linha in pedidos:
        pedido = linha.strip('\n')

        if pedido in produtos.keys():
            print('_-' * 10, f'Produto {pedido}:', '_-' * 10)
            print(f'R${float(produtos[pedido][0])}') 
            print(f'{produtos[pedido][1]} unidades disponiveis.')
            print()
        else:
            print(f'Produto {pedido} INDISPONÍVEL.')
    pedidos.close

#PP
nome_arq = input('Digite o nome do arquivo contendo os produtos: ')
produtos = criarDatabase(nome_arq)

mostrar(produtos)
produtosVencendo(produtos)

nome_cliente = input('Digite o nome do arquivo contendo os pedidos: ')
buscaProduto(nome_cliente, produtos)
print()
print('PROGAMA FINALIZADO')