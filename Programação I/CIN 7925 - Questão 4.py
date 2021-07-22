
listaDeCompras = [];
comprarMais = input("Deseja comprar mais algum produto? (s/n)")
while comprarMais == "s":
    novoItem = input("Digite o nome, preço e quantidade, separados por virgula: ").split(',')
    listaDeCompras.append(novoItem)
        
    comprarMais = input("Deseja comprar mais algum produto? (s/n)")
    
#Para cada elemento da lista, faça
for i in listaDeCompras:
    #Olhar a lista que está no indíce i e faça
    if listaDeCompras[i][2] >= 6:
        print (i+1')',listaDeCompras[i][0],'(R$',float(listaDeCompras[i][1])',',listaDeCompras[i][2],'unidade): R$'+float(listaDeCompras[i][1])*listaDeCompras[i][2],'-',float(listaDeCompras[i][1])*listaDeCompras[i][2]*(0,2)'(desconto) =',float(listaDeCompras[i][1])*listaDeCompras[i][2]*0,8)
        
    elif listaDeCompras[i][2] > 1:
        print (i+1')',listaDeCompras[i][0],'(R$',float(listaDeCompras[i][1])',',listaDeCompras[i][2],'unidades): R$'+float(listaDeCompras[i][1]*listaDeCompras[i][2]))
           
    else:    
        print (i+1')',listaDeCompras[i][0],'(R$',float(listaDeCompras[i][1])',',listaDeCompras[i][2],'unidade): R$'+float(listaDeCompras[i][1]*listaDeCompras[i][2]))
        