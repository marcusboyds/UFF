medias = input().split()
n1 = float(medias[0])
n2 = float(medias[1])
n3 = float(medias[2])
n4 = float(medias[3])
media = float((n1*2+n2*3+n3*4+n4*1)/10)
print (f'Media: {media:.1f}')
if media >= 7.0:
    print ('Aluno aprovado.')
if media < 5:
    print ('Aluno reprovado.')
if 5 <= media <= 6.9:
    print ('Aluno em exame.')
    exame = float(input(''))
    print(f'Nota do exame: {exame:.1f}')
    media_final = float((media + exame) / 2)
    if media_final >= 5:
        print ('Aluno aprovado.')
    if media_final <= 4.9:
        print ('Aluno reprovado.')
    print (f'Media final: {media_final:.1f}')