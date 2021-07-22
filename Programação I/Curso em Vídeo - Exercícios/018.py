import math
a = float(input('Digite o ângulo que você deseja: '))
r = math.pi * a / 180
sen = math.sin(r)
cos = math.cos(r)
tan = math.tan(r)
print ('O angulo de {} tem o SENO de {:.2f}'.format(a,sen))
print ('O angulo de {} tem o COSSENO de {:.2f}'.format(a,cos))
print ('O angulo de {} tem o TANGENTE de {:.2f}'.format(a,tan))