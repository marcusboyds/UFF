a = int(input())

for _ in range(a):
    n = int(input())
    proximo = 1
    anterior = 0
    fibonacci = 0
    for i in range(1, n):
        fibonacci = proximo + anterior
        anterior = proximo
        proximo = fibonacci
    print (f'Fib({n}) = {fibonacci}')