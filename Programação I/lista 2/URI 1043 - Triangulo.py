a,b,c = input().split()
a = float(a)
b = float(b)
c = float(c)

if abs(b-c) < a < b+c:
    if abs(a-c) < b < a+c:
        if abs(b-b) < c < a+b:
            print ('Perimetro =',a+b+c)
else:
    print ('Area =',(a+b)*c/2)