a = input('')
b = input('')
c = input('')

animais = {'aguia': ['carnivoro', 'ave', 'vertebrado'],
            'pomba': ['onivoro', 'ave', 'vertebrado'],
           'homem': ['onivoro', 'mamifero', 'vertebrado'],
            'vaca': ['herbivoro', 'mamifero', 'vertebrado'],
           'pulga': ['hematofago', 'inseto', 'invertebrado'],
           'lagarta': ['herbivoro', 'inseto', 'invertebrado'],
            'sanguessuga': ['hematofago', 'anelideo', 'invertebrado'],
           'minhoca': ['invertebrado', 'anelideo', 'onivoro']}

for animal in animais.keys():
    
    if a in animais[animal]:
        if b in animais[animal]:
            if c in animais[animal]:
                print (animal)