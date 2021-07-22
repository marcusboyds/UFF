from PPlay import window
from PPlay import gameimage
from PPlay import mouse
from PPlay.window import *
from PPlay.gameimage import *
from PPlay.sprite import *
import random

#Incialização
janela = Window(920, 624)
janela.set_background_color([255,255,0])
janela.set_title("Jogo Extremamente Bom")
teclado = Window.get_keyboard()

fundo = GameImage("fundo.png")
padA = Sprite("pad.png", 1)
padB = Sprite("pad.png", 1)
bola = Sprite("bola.png", 1)
allspark = Sprite("allspark.png", 1)
placarA = 0
placarB = 0


#Posição da Bola
bola.x = janela.width/2 - bola.width/2
bola.y = janela.height/2 - bola.height/2
velx = 4
vely = 4
velpad = 300
relogio = 0
contadorFrames = 0

#Posição dos Pads
#Eixo X
padA.x = janela.width/6
padB.x = (janela.width/6)*5
#Eixo Y
padA.y = janela.height/4
padB.y = janela.height/4

#Game Loop
while True:
    #Entrada de Dados
    padA.move_key_y(4)

    #IA
    if ((padB.y) < bola.y) and padB.y >= 0:
        padB.y = padB.y + velpad * janela.delta_time()
    elif ((padB.y) > bola.y) and (padB.y + padB.height) <= janela.height: 
        padB.y = padB.y - velpad * janela.delta_time()

    #Updates
    bola.x = bola.x + velx
    bola.y = bola.y + vely

    #Teste de Colisão
    if (bola.y  < 0)or(bola.y + bola.height >= janela.height):
        vely = vely*-1
        
    #Colisão Pads
    if(padA.collided(bola))or padB.collided(bola):
        velx = velx*-1
        if padA.collided(bola):
            bola.x = padA.x + padA.width
        if padB.collided(bola):
            bola.x = padB.x - padB.width - bola.width        

    #Colisao Allspark
    if allspark.collided(bola):
        velx = velx *-1
        allspark.x = random.randint(int(janela.width/8), int((janela.width-janela.width/8)))
        allspark.y = random.randint(int(janela.height/8), int((janela.height-janela.height/8)))
    
    
    #Saindo em todo o Fundo    
    if(bola.x <= 0):
        placarA += 1
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()
    if(bola.x >= janela.width):
        placarB += 1
        velpad += 30  
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()     

    #Desenho
    fundo.draw()
    allspark.draw()
    padA.draw()
    padB.draw()
    bola.draw()
    janela.draw_text(str(placarA), (janela.width/8), 20, size=100, color=(139,63,209), font_name="Arial", bold=False, italic=False) 
    janela.draw_text(str(placarB), ((janela.width/8)*5), 20, size=100, color=(139,63,209), font_name="Arial", bold=False, italic=False) 
    relogio += janela.delta_time()
    contadorFrames+= 1
    if relogio >= 1:
        janela.draw_text(str(contadorFrames), janela.width/2, janela.height-100, size=100, color=(139,63,209), font_name="Arial", bold=False, italic=True)
        print(contadorFrames)
        relogio = 0
        contadorFrames = 0
    
    janela.update()

#Encerramento