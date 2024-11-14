import pygame
from sys import exit


def display_score(current_score):
    score_surf = font.render(f"{current_score}", None, (64,64,64))
    score_rect = score_surf.get_rect(center=SCORE_POS)
    screen.blit(score_surf, score_rect)

def show_top_score():
    top_score_surf = font.render(f"Top score = {top_score}", None, (64,64,64))
    top_score_rect = top_score_surf.get_rect(topleft=TOP_SCORE_POS)
    screen.blit(top_score_surf, top_score_rect)


SCREEN_WIDTH = 720
SCREEN_HEIGHT = 480
SCREEN_SIZE = (SCREEN_WIDTH, SCREEN_HEIGHT)
SCORE_POS = (360,50)
TOP_SCORE_POS = (0,100)
FLOOR_START_HEIGHT = 425
game_active = False

clock = pygame.time.Clock()
FPS = 60

pygame.init()

font = pygame.font.Font(None, 50)
font_bigger = pygame.font.Font(None, 80)

screen = pygame.display.set_mode(SCREEN_SIZE)

# BACKGROUND
original_background_img = pygame.image.load("mountains_background.png")
background_img_size = SCREEN_SIZE
background_img = pygame.transform.scale(original_background_img, background_img_size)

# SCORE
# score_surf = font.render("Score", False, "black")
# score_rect = score_surf.get_rect(center=(360,150))

# CHARACTER
CHARACTER_STARTER_POSITION = (75,275)
original_character_img = pygame.image.load("character.png")
character_img_size = (200,200)
character_img = pygame.transform.scale(original_character_img, character_img_size).convert_alpha()
character_rect = character_img.get_rect(topleft=CHARACTER_STARTER_POSITION)
character_gravity = 0
# CHARACTER DOWN
original_char_down_img = pygame.image.load("character_down.png")
character_down_img = pygame.transform.scale(original_char_down_img, character_img_size).convert_alpha()

# CHARACTER MENU IMG
CHARACTER_MENU_POS = (360,240)
character_menu_img = pygame.transform.scale(original_character_img, (300,300)).convert_alpha()
character_menu_rect = character_menu_img.get_rect(center=(CHARACTER_MENU_POS))

# ENEMY
ENEMY_STARTER_POSITION = (550, FLOOR_START_HEIGHT)
original_enemy_img = pygame.image.load("enemy.png")
enemy_img_size = (100, 100)
enemy_img = pygame.transform.scale(original_enemy_img, enemy_img_size).convert_alpha()
enemy_rect = enemy_img.get_rect(bottomleft=ENEMY_STARTER_POSITION)

# NAME OF GAME
NAME_POSITION = (360,50)
name_surf = font_bigger.render("Mexican Runner", False, (64,64,64))
name_rect = name_surf.get_rect(center=(NAME_POSITION))

# PRESS SPACE TO START
PRESS_SPACE_TO_START_POSITION = (360,430)
space_to_start_surf = font_bigger.render("Press space to start", False, (64,64,64))
space_to_start_rect = space_to_start_surf.get_rect(center=(PRESS_SPACE_TO_START_POSITION))

current_score = 0
top_score = 0
jumping = False

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

        if game_active:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and character_rect.bottom == FLOOR_START_HEIGHT:
                    screen.blit(character_down_img, character_rect)
                    pygame.display.flip()
                    character_gravity -= 23
                    jumping = True
                    pygame.time.delay(10)
                    character_img = character_down_img
        else:
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                    game_active = True
                    enemy_rect.left = 720
                    current_score = 0
        
    if game_active:
        #screen.blit(floor, floor_rect)
        screen.blit(background_img, (0,0))
        screen.blit(enemy_img, enemy_rect)
        display_score(current_score)

        # ENEMY
        if current_score < 5:
            enemy_rect.x -= 6
        elif 10 > current_score >= 5:
            enemy_rect.x -= 9
        elif 15 > current_score >= 10:
            enemy_rect.x -= 12
        
        if enemy_rect.right <= 0:
            enemy_rect.left = SCREEN_WIDTH

        # PLAYER
        character_gravity += 1
        character_rect.y += character_gravity
        if character_rect.bottom >= FLOOR_START_HEIGHT:
            character_rect.bottom = FLOOR_START_HEIGHT
            character_gravity = 0
            jumping = False
            character_img = pygame.transform.scale(original_character_img, character_img_size).convert_alpha()
        if jumping:
            screen.blit(character_down_img, character_rect)
        else:
            screen.blit(character_img, character_rect)


        collision_distance = 60
        if character_rect.colliderect(enemy_rect) and abs(character_rect.centerx - enemy_rect.centerx) < collision_distance:
            game_active = False

        if current_score < 10:
            score_change_threshold = 4
        elif 10 <= current_score <= 20:
            score_change_threshold = 6
        if abs(character_rect.centerx - enemy_rect.centerx) < score_change_threshold:
            current_score += 1

    else:
        screen.fill("lightblue")
        screen.blit(name_surf, name_rect)
        screen.blit(space_to_start_surf, space_to_start_rect)
        screen.blit(character_menu_img, character_menu_rect)
        if current_score > top_score:
            top_score = current_score
        show_top_score()
        
    



    





    pygame.display.update()
    clock.tick(FPS)
