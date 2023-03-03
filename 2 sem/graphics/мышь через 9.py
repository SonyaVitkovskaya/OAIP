import pygame
pygame.init()

back_ground = pygame.image.load("фон.jpg")

window = pygame.display.set_mode((800,500))
screen = pygame.Surface((800, 500))
mouse = pygame.image.load("мышь.png")

l_u="lu"
r_u="ru"
l_d="ld"
r_d="rd"
up="up"
space="space"
down = "down"
right = "right"
left = "left"
stop = "stop"

action=stop

running=True

x = 0
y = 0
while running:
    for i in pygame.event.get():
        if i.type == pygame.QUIT:
            running = False
        elif i.type == pygame.KEYDOWN:
            if i.key == pygame.K_RIGHT:
               action = right
            elif i.key == pygame.K_LEFT:
                action = left
            elif i.key == pygame.K_UP:
                action = up 
            elif  i.key == pygame.K_DOWN:
                action = down
            elif i.key == pygame.K_o:
                action = l_u
            elif i.key == pygame.K_p:
                action = r_u
            elif i.key == pygame.K_k:
                action = l_d
            elif i.key == pygame.K_l:
                action = r_d
        elif i.type == pygame.KEYUP:
            if i.key in [pygame.K_LEFT, pygame.K_RIGHT, pygame.K_UP, pygame.K_SPACE, pygame.K_DOWN,pygame.K_o,pygame.K_l,pygame.K_k,pygame.K_p]:
                action = stop
    if action == right:
        x += 5
    elif action == left:
        x -= 5
    elif action == up:
        y -= 5
    elif action == down:
        y += 5
    elif action == stop:
        x=x
        y=y
    elif action == l_u:
        x -= 3
        y -= 3
    elif action == r_u:
        x += 3
        y -= 3
    elif action == l_d:
        x -= 3
        y += 3
    elif action == r_d:
        x += 3
        y += 3
    window.blit(screen, (0,0))
    screen.blit(back_ground, (0,0))
    screen.blit(mouse, (x, y))

    pygame.display.update()

pygame.quit()
