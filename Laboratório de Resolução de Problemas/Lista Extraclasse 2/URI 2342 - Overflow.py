n = int(input())
p, c, q = input().split()
p = int(p)
q = int(q)
if c == '*':
    resultado = p*q
    if resultado > n:
        print('OVERFLOW')
    else:
        print(OK)
elif c== '+':
    resultado = p+q
    if resultado > n:
        print('OVERFLOW')
    else:
        print('OK')