#Ler n
n = int(input())
t = 1

#Enquanto n =! 0, faça
while n != 0:
#Imprimir teste n
    print (f'Teste {t}')
    #Jogador1 <- recebe nome do primeiro jogador, que é par
    j1 = input('')
    #Jogador2 <- recebe nome do primeiro jogador, que é impar
    j2 = input('')
    #Inputar n vezes dois inteiros A e B
    for i in range (n):
        a, b = input().split()
        a = int(a)
        b = int(b)
        #Decidir quem ganhou
        if (a+b) % 2 == 0:
            print (j1)
        else:
            print (j2)
    print ('')
    t += 1
    n = int(input()) 
    #Imprimir linha vazia
#Ler N