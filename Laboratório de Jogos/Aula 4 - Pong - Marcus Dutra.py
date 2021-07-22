from PPlay import window
from PPlay import gameimage
from PPlay import mouse
from PPlay.window import *
from PPlay.gameimage import *
from PPlay.sprite import *


#Incialização
janela = Window(920, 624)
janela.set_background_color([255,255,0])
janela.set_title("Jogo Extremamente Bom")
teclado = Window.get_keyboard()

fundo = GameImage("fundo.png")
padA = Sprite("pad.png", 1)
padB = Sprite("pad.png", 1)
bola = Sprite("bola.png", 1)
placarA = 0
placarB = 0


#Posição da Bola
bola.x = janela.width/2 - bola.width/2 * janela.delta_time()
bola.y = janela.height/2 - bola.height/2 * janela.delta_time()
velx = 40
vely = 1

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
    

    if ((padB.y) < bola.y) and padB.y >= 0:
       padB.y = padB.y + 4 * janela.delta_time()
    elif ((padB.y) > bola.y) and (padB.y +padB.height) <= janela.height: 
       padB.y =padB.y - 4 * janela.delta_time()

    #Updates
    bola.x = bola.x + velx
    bola.y = bola.y + vely

    #Teste de Colisão
    if (bola.collided(padB)or(bola.collided(padA))):
        velx = velx*-1
    if (bola.collided(padB)or(bola.collided(padA))):
        vely = vely*-1
    #Saindo em todo o Fundo    
    if(bola.x <= 0):
        placarA += 1
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()
    if(bola.x >= janela.width):
        placarB += 1
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()
    
    #Saindo nas Laterais EM CIMA
    if(bola.y <= 0)and(bola.x < janela.height/2):
        placarA += 1
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()
    if(bola. y<= 0)and(bola.x > janela.height/2):
        placarA += 1
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()      

    #Saindo nas Laterais EM BAIXO
    if(bola.y <= 0)and(bola.x < janela.height/2):
        placarA += 1
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()
    if(bola. y<= 0)and(bola.x > janela.height/2):
        placarA += 1
        bola.x = janela.width/2 - bola.width/2
        bola.y = janela.height/2 - bola.height/2
        janela.update()  
    #Desenho
    fundo.draw()
    padA.draw()
    padB.draw()
    bola.draw()
    #PlacarA
    janela.draw_text(str(placarA), (janela.width/8), 20, size=100, color=(139,63,209), font_name="Arial", bold=False, italic=False)
    #PlacarB
    janela.draw_text(str(placarB), ((janela.width/8)*5), 20, size=100, color=(139,63,209), font_name="Arial", bold=False, italic=False)
    janela.update()

#Encerramento