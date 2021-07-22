x0, y0, x1, y1 = map(int, input().split())
a0, b0, a1, b1 = map(int, input().split())

#Desvios Condicionais

#1º Caso
if a0 <= x1 and b0 <= y1:
    print('1')
elif y0 <= b1 and x1 >= a0:
    print('1')
elif a1 <= x0 and b1 >= y0:
    print('1')
elif a1 >= x0 and b0 <= y1:
    print('1')
else:
    print('0')