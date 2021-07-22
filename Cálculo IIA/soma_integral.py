
#f(x)=x
def f(x):
    return x

#Repartições do Gráfico
n = 10000

a = int(input("Digite o a: "))
b = int(input("Digite o b: "))

intervalo = (a,b)

base = b-a # Se a=0 b=2, base=2.
soma_integral = 0

for i in range(1,n+1):
    retangulo_elementar = (base/n) * (i/n)
    soma_integral += retangulo_elementar

print(soma_integral)
