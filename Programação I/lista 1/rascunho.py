opcao = input("Olá, mestre, c ou e?: ")

if opcao == "e":
    c = int(input("Insira aqui a característica: "))
    e = c - 127
    print ("Seu expoente é", e)

if opcao == "c":
    e = int(input("Insira aqui o expoente: "))
    c = 127 + e
    print ("Sua característica é", c)