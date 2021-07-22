def imprimirSenha(frase):
    senha = []
    for palavra in frase:
        senha.append(palavra[0])
    print(''.join(senha))

n = int(input())

frases = []

#Adicionar a frase a lista de frases
for i in range(n):
    frase = input().split()
    frases.append(frase)
    
#Imprimir as senhas
for i in range(n):    
    imprimirSenha(frases[i])