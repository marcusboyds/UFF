#Ler salário
renda = float(input())
i1 = 0
i2 = 0
i3 = 0
#Calcular imposto de renda
    #Se renda for < R$ 2000
if renda < 2000:
    print ('Isento')
        #Isento
    #Se renda --> 2000.01 < renda < 3000.00
if renda >= 3000.00:   
        #Cobrar 8% de renda entre 2000.01 até 3000.00
    i1 = 0.08*(renda-2000)  
    #Se renda --> 3000.01 < renda < 4500.00
if renda <= 4500.00:     
        #Cobrar 18% de renda entre 3000.01 até 4500.00
    i2= 0.18*(renda-3000)  
    #Se renda for 4500.00
if renda > 4500:
    i3 = 0.28*(renda-4500)
        #Cobrar 28% de renda maior que 4500
#Somar cobranças
#Mostrar imposto final