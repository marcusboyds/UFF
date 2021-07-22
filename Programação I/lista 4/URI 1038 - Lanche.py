#Algoritmo: Entra preço e quantidade e imprime preço total.

lista = [4.00,4.50,5.00,2.00,1.50]
    
preco, quantidade = input().split()
preco = int(preco)
quantidade = int(quantidade)

print('Total: R$ {:.2f}'.format(lista[preco-1]*quantidade))
