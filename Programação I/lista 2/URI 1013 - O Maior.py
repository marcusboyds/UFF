
'''
def maiorTermo(a,b,c):
    #definir a como maior termo
    if a>b and a>c:
        maior = a
        if b>c:
            meio_termo = b
            menor = c
        else:
            meio_termo = c
            menor = b
    #definir a como termo do meio
    elif a>b and c>a:
        meio_termo = a
        menor = b
        maior = c
    elif a>c and b>a:
        meio_termo = a
        maior = b
        menor = c
    #definir a como menor termo
    if a<b and a<c:
        menor = a
        if b>c:
            maior = b
            meio_termo = c
        else:
            meio_termo = c
            maior = b
        
        return maior and meio_termo
'''
            
#ProgamaPrincipal
a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)

maior = 0
menor = 0
meio_termo = 0

if a>b and a>c:
    maior = a
    if b>c:
        meio_termo = b
        menor = c
    else:
        meio_termo = c
        menor = b
    #definir a como termo do meio
elif a>b and c>a:
        meio_termo = a
        menor = b
        maior = c
elif a>c and b>a:
        meio_termo = a
        maior = b
        menor = c
    #definir a como menor termo
if a<b and a<c:
    menor = a
    if b>c:
        maior = b
        meio_termo = c
    else:
        meio_termo = c
        maior = b
            

print(f'{maior} eh o maior')