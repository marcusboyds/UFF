x = ' '

a, b, c, d = input().split()
a = int(a)
b = float(b)
c = str(c)
d = d[:50]



print((str(a)+str(b)+str(c)+str(d)))

print(str(a)+str(x*8)+str(b)+str(x*8)+str(c)+str(x*8)+str(d))

print(str(a)+str(x*10)+str(b)+str(x*10)+str(c)+str(x*10)+str(d))