l, n = list(map(int, input().split()))

placas = []

for i in range(n):
    placas.append(list(map(int, input().split())))
    
#Transformar as entradas em placa com cordenadas x1 e x2
for i in range(n):
    placas[i][1] += placas[i][0]

#Primeiro valor assumido pela primeira placa
area_tampada = placas[0][1] - placas[0][0]     

#Calcular área tampada por cada placa depois da primeira
for i in range(1, n):
    x1, x2 = placa[i][0], placa[i][1]
    #Area da placa assumida
    area_placa = x2 - x1
    #Calcular interseção
    for j in range(i, 0, -1):
        x3, x4 = placa[j][0], placa[j][1]
        if x1 <= x3 <= x2 and x1 <= x3 <= x2:
            area_placa = x2 - x1
        elif x1 <= x3 <= x2:
            area_placa -= x2 - x3
        elif
    area_tampada += area_placa
    
area_vazao = (600*100) - (area_tampada*100)

print(area_vazao)