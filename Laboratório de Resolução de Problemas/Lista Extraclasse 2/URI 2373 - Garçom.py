n = int(input())
copos_quebrados = 0
for _ in range(n):
    latas, copos = input().split()
    latas = int(latas)
    copos = int(copos)
    if latas > copos:
        copos_quebrados += copos
print(copos_quebrados)

    