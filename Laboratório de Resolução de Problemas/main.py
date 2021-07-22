import math
import sys

# Ler 3 (a, b, c) valores de ponto flutuantes
entrada = input().split(' ')
a = float(entrada[0])
b = float(entrada[1])
c = float(entrada[2])
# Calcular Bhaskara
# Se for a = 0
if a == 0:
    print("Impossível Calcular")
    sys.exit(0)
# Calcular delta
delta = b ** 2 - 4 * a * c
# Se delta < 0
if delta < 0:
    # Impossível Calcular
    print("Impossível Calcular")
    sys.exit(0)
# Calcular duas raízes da equação
# Raíz 1
R1 = ((-b + math.sqrt(delta)) / (2 * a))
# (-b+raiz de delta)/2a
# Raíz 2
R2 = ((-b - math.sqrt(delta)) / (2 * a))
# (-b-raiz de delta)/2a
# Mostrar
print("R1 =", "%.5f" % R1)
print("R2 =", "%.5f" % R2)


