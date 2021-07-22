def minha_chave(arg):
    estado = 0
    if arg[1] == 'YES':
        estado = 0
    else:
        estado = 1
    return estado

def minha_chave2(arg):
    estado = 0
    if arg[1] == 'YES':
        estado = 0
    else:
        estado = 1
    return estado, -len(arg[0])

def minha_chave3(arg):
    estado = 0 
    if arg[1] == "YES":
        estado = 0
    else:
        estado = 1
    return estado, arg[0]

def remover_parecidos(lista):
    l =[]
    for i in lista:
        if i not in l:
            l.append(i)
    return l
    
entrada = 0
inscritos = []

while entrada != ["FIM"]:
    entrada = input().split()
    if entrada != ['FIM']:
        inscritos.append(entrada)
        
inscritos_copia = inscritos.copy()     

#Mostrar inscritos em ordem alfabética
inscritos.sort(key=minha_chave3)
inscritos = remover_parecidos(inscritos)
for i in range(len(inscritos)):
    print(inscritos[i][0])

#Printar ganhador
inscritos_copia.sort(key=minha_chave)
inscritos_copia.sort(key=minha_chave2)
ganhador = inscritos_copia[0][0]
print('')
print('Amigo do Habay:')
print(ganhador)
