import random

arquivo = open('random_nums.txt', 'w')
for i in range (100):
    arquivo.write(str(random.randint(1,100)))
    arquivo.write(str('\n'))
arquivo.close()