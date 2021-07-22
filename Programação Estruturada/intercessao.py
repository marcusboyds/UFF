A = [1,2,3,4,5,6]
B = [6,7,8,9,10,8]
intercessao = []

for i in range(len(A)):
    if A[i] == B[i]:
        intercessao[i] = A[i]

print(intercessao)