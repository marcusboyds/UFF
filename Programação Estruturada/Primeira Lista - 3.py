def sort(lista):
    for i in range(1, len(lista)):
        valor = lista[i]

        j = i - 1
        while(j >= 0 and lista[j] > valor):
            lista[j+1] = lista[j]
            j -= 1
    
        lista[j+1] = valor

    return print(vetor)

vetor = [5,3,6,2,1,8,6,2]

sort(vetor)
