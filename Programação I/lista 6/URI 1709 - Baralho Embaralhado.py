def split_list(a_list):
    half = len(a_list)//2
    return a_list[:half], a_list[half:]

n = int(input())
lista = []

for i in range(n):
    lista.append(i+1)
    
#Dividir a lista em duas sublistas


c = 1
nova_lista = lista.copy()
a, b = split_list(nova_lista)
if len(a) != len(b):
    nova_lista = list(sum(zip(b,a),()))
    nova_lista.append(b[-1])
else:
    nova_lista = list(sum(zip(b,a),()))

while nova_lista != lista:
    a, b = split_list(nova_lista)
    if len(a) != len(b):
        nova_lista = list(sum(zip(b,a),()))
        nova_lista.append(b[-1])
    else:
        nova_lista = list(sum(zip(b,a),()))
    c += 1

print(c)