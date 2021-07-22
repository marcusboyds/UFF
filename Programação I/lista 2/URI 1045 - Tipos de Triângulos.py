import sys

def angulo(a,b,c):
    if a**2>b**2+c**2:
        print ('TRIANGULO OBTUSANGULO')
    elif a**2<b**2+c**2:
        print ('TRIANGULO ACUTANGULO')
    return None

def lado(a,b,c):
    if a==b or c==a or c==b:
        print ('TRIANGULO ISOCELES')
    return None

n1, n2, n3 = input().split()

n1 = float(n1)
n2 = float(n2)
n3 = float(n3)

a=0
b=0
c=0

#definir se n1 é o maior
if n1>n2 and n1>n3:
    a = n1
    if n2>n3:
        b = n2
        c = n3
    else:
        c = n2
        b = n3
#definir se n1 é o do meio
if n2>n1 and n3<n1:
    b = n1
    a = n2
    c = n3
elif n3>n1 and n2<n1:
    b = n1
    c = n2
    a = n3
#definir se n1 é o menor
if n1<n2 and n1<n3:
    c = n1
    if n2>n3:
        b = n3
        a = n2
    else:
        a = n3
        b = n2
#definir ordem com dois números iguais
if n1==n2 and n2<n3:
    a = n3
    b = n2
    c = n1
elif n1==n2 and n2>n3:
    a = n1
    b = n2
    c = n3
elif n1==n3 and n3>n2:
    a = n1
    b = n2
    c = n3
elif n1==n3 and n3<n2:
    b = n1
    a = n2
    c = n3
elif n2==n3 and n1>n2:
    a = n1
    b = n2
    c = n3
elif n2==n3 and n1<n2:
    c = n1
    b = n2
    a = n3
elif n1==n2==n3:
    a = n1
    b = n2
    c = n3
    
if a==0 and b==0 and c==0:
    print ('NAO FORMA TRIANGULO')
    sys.exit()
    
if a==b==c:
    angulo(a,b,c)
    print ('TRIANGULO EQUILATERO')
    sys.exit()

if a>=b+c:
    print ('NAO FORMA TRIANGULO')
    sys.exit()
    
if a**2==b**2+c**2:
    print ('TRIANGULO RETANGULO')
    sys.exit()

angulo(a,b,c)
lado(a,b,c)

