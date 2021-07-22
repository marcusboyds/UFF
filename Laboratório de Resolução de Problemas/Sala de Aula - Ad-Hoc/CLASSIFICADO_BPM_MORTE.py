
class Vivo:
    def __init__(self, freq_cardiaca, respiracao):
        self.freq_cardiaca = freq_cardiaca
        self.respiracao = respiracao

freq_cardiaca = int(input('Digite a frequencia cardiaca: '))
respiracao = bool(input('Voce respiracao: '))

pessoa = Vivo(freq_cardiaca, respiracao)

if pessoa.respiracao == True:
    if pessoa.freq_cardiaca < 100:
        print('Vivo e descansado')
    else:
        print('Vivo e cansando')
else:
    print('Morto')
