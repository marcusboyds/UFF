total_dias = int(input(''))

print(int(total_dias/365), "ano(s)")
print(int((total_dias%365)/30), "mes(es)")
print(int((total_dias%365)%30), "dia(s)")

'''
#Ler idade em dias
idade = int(input())
#Contar a cada 365 dos dias e dar 1 ano, até não restar mais nada
ano = int(idade % 365)
#Contar a cada 30 dias e dar 1 mes, até não ter mais 30
meses = int((idade-ano*365) / 30 )
#Contar dias
dias = int(idade-((ano*365)+(meses*30)))
print (ano,"anos(s)")
print (meses,"mes(es)")
print (dias,"dia(s)")
'''

'''
idade = int(input())
anos = int(idade / 365)
meses = int((idade-anos*365) % 12)
dias = (idade % 365 % 30)
print(anos,"ano(s)")
print(meses,"mes(es)")
print(dias,"dia(s)")
'''