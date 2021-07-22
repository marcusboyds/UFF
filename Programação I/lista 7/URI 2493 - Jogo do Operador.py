while True:
  try:
    operadores = {
      "+": lambda op1, op2: op1 + op2,
      "-": lambda op1, op2: op1 - op2,
      "*": lambda op1, op2: op1 * op2,
      "/": lambda op1, op2: op1 / op2
    }

    def calculadora(operator, expressao):
       if expressao[n-1][0] == '-':
           op1 = int(expressao[n-1][1])*-1
       else:
           op1 = int(expressao[n-1][0])
       if expressao[n-1][3] == '-':
           op2 = int(expressao[n-1][4])*-1
       else:
           op2 = int(expressao[n-1][3])
       return int(operadores[operator](op1, op2))


    #Expressões dos jogadores e jogadores
    t = int(input())

    #Armazenamento de expressões
    entrada = [None]*t
    for i in range(t):
        entrada[i] = input()

    #Validar perdedores
    perdedores = []
    pattern = []
    for i in range(t):
        nome, n, r = input().split()
        n = int(n)
        
        if entrada[n-1][-2] == '-':
            resultado = int(entrada[n-1][-1])*-1
        else:
            resultado = int(entrada[n-1][-1])
        if r == 'I':
            if int(entrada[n-1][0])*int(entrada[n-1][2]) == resultado or int(entrada[n-1][0])+int(entrada[n-1][2]) == resultado or int(entrada[n-1][0])-int(entrada[n-1][2]) == resultado:
                perdedores.append(nome)
        elif calculadora(r, entrada) != resultado:
            perdedores.append(nome)
     
    perdedores.sort() 
     
    if len(perdedores) < t:
        print(' '.join(perdedores))
    elif pattern == perdedores:
        print('You Shall All Pass!')
    elif len(perdedores) == t:
        print('None Shall Pass!')

  except EOFError:
    break