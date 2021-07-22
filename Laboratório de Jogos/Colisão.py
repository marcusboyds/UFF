# Como sempre, importamos nossa janela
from PPlay.window import *
# E agora o Sprite - que herda os métodos de GameObject
from PPlay.sprite import *
 
janela = Window(500,500)
ball1 = Sprite("bola.png")
ball2 = Sprite("bola.png")
 
# Definir uma posição inicial para cada uma delas
ball1.set_position(100,0)
ball2.set_position(100,1000)
 
# Velocidade
ball1_speed = 120  # POSITIVO É PRA BAIXO!!!
ball2_speed = -120  # NEGATIVO É PRA CIMA!!!
 
while(True):
    janela.set_background_color((255,255,255))
     
    # Irei mover ambas balls uma na direção da outra
    # EIXO Y POSITIVO É PARA BAIXO!!!
    ball1.move_y(ball1_speed * janela.delta_time()) 
    ball2.move_y(ball2_speed * janela.delta_time())
     
    # Checa se ball1 colidiu com ball2 (tanto faz a ordem)
    # if(ball2.collided(ball1)):
    if(ball1.collided(ball2)):
        ball1_speed = 0  # fica no lugar
        ball2_speed = 0
         
        print("Colidiram em:", ball2.y)                 
     
    ball1.draw()
    ball2.draw()
     
    janela.update()  