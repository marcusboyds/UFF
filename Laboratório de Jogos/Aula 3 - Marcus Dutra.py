from PPlay import window
from PPlay import gameimage
from PPlay.window import *
from PPlay.gameimage import *
from PPlay.sprite import *

#Incialização
janela = Window(920, 624)
janela.set_background_color([255,255,0])
janela.set_title("Jogo Extremamente Bom")

fundo = GameImage("fundo.png")
bola = Sprite("bola.png", 1)

#Posição da Bola
'''
bola.x = 460-256
bola.y = 312-246
'''
bola.x = janela.width/2 - bola.width/2
bola.y = janela.height/2 - bola.height/2
velx = 1
vely = 1

#Game Loop
while True:
    #Entrada de Dados

    #Updates
    bola.x = bola.x + velx
    bola.y = bola.y + vely

    #Teste de Colisão
    if (bola.x + bola.width >= janela.width)or(bola.x <= 0):
        velx = velx*-1
    if (bola.y + bola.height >= janela.height)or(bola.y <= 0):
        vely = vely*-1

    #Desenho
    fundo.draw()
    bola.draw()
    janela.update()

#Encerramento