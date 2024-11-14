import pygame
from sys import exit
from random import randint, choice


# IMPORTANT VAR
SCREEN_WIDTH = 1080
SCREEN_HEIGHT = 720
SCREEN_SIZE = (SCREEN_WIDTH, SCREEN_HEIGHT)

PLAYER_FLOOR_START_HEIGHT = 600
PLAYER_SIZE = (300,300)
PLAYER_POSITION = (100,PLAYER_FLOOR_START_HEIGHT)

CACTUS_SIZE = (150,150)
CACTUS_Y_POS = 600

TURTLE_SIZE = (150,150)
TURTLE_Y_POS = 600

BIRD_SIZE = (150,150)
BIRD_Y_POS = 280

SCORE_POSITION = (540, 50)


FPS = 60

# START PYGAME
pygame.init()

# SPRITE CLASSES
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        player_1 = pygame.image.load("graphics/character/character_1.png")
        player_1 = pygame.transform.scale(player_1, PLAYER_SIZE).convert_alpha()
        player_2 = pygame.image.load("graphics/character/character_2.png")
        player_2 = pygame.transform.scale(player_2, PLAYER_SIZE).convert_alpha()
        player_3 = pygame.image.load("graphics/character/character_3.png")
        player_3 = pygame.transform.scale(player_3, PLAYER_SIZE).convert_alpha()
        self.player_jump = [player_1, player_2, player_3]
        self.frame_count = 0
        self.frames_per_state = 60

        self.image = self.player_jump[0]
        self.rect = self.image.get_rect(topleft=(50,PLAYER_FLOOR_START_HEIGHT))
        self.gravity = 0

    def player_input(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_SPACE] and self.rect.bottom == PLAYER_FLOOR_START_HEIGHT:
            self.gravity = -28

    def apply_gravity(self):
        self.gravity += 1
        self.rect.y += self.gravity
        if self.rect.bottom >= PLAYER_FLOOR_START_HEIGHT:
            self.rect.bottom = PLAYER_FLOOR_START_HEIGHT

    def animation_state(self):
        if self.rect.bottom < PLAYER_FLOOR_START_HEIGHT:
            self.frame_count += 1
            if self.frame_count < self.frames_per_state / 3:
                self.image = self.player_jump[1]
            elif self.frame_count < 2 * (self.frames_per_state / 3):
                self.image = self.player_jump[2]
            else:
                self.image = self.player_jump[0]
                self.frame_count = 0
        else:
            self.image = self.player_jump[0]
            self.frame_count = 0

    def update(self):
        self.player_input()
        self.apply_gravity()
        self.animation_state()

class Obstacle(pygame.sprite.Sprite):
    def __init__(self,type):
        super().__init__()
        
        if type == "cactus":
            cactus_1 = pygame.image.load("graphics/obstacles/cactus/cactus_1.png")
            cactus_1 = pygame.transform.scale(cactus_1, CACTUS_SIZE).convert_alpha()
            cactus_2 = pygame.image.load("graphics/obstacles/cactus/cactus_2.png")
            cactus_2 = pygame.transform.scale(cactus_2, CACTUS_SIZE).convert_alpha()
            self.frames = [cactus_1, cactus_2]
            y_pos = CACTUS_Y_POS
        elif type == "turtle":
            turtle_1 = pygame.image.load("graphics/obstacles/turtle/turtle_1.png")
            turtle_1 = pygame.transform.scale(turtle_1, TURTLE_SIZE).convert_alpha()
            turtle_2 = pygame.image.load("graphics/obstacles/turtle/turtle_2.png")
            turtle_2 = pygame.transform.scale(turtle_2, TURTLE_SIZE).convert_alpha()
            self.frames = [turtle_1, turtle_2]
            y_pos = TURTLE_Y_POS
            
        else:
            bird_1 = pygame.image.load("graphics/obstacles/bird/bird_1.png")
            bird_1 = pygame.transform.scale(bird_1, BIRD_SIZE).convert_alpha()
            bird_2 = pygame.image.load("graphics/obstacles/bird/bird_2.png")
            bird_2 = pygame.transform.scale(bird_2, BIRD_SIZE).convert_alpha()
            self.frames = [bird_1, bird_2]
            y_pos = BIRD_Y_POS

        self.animation_index = 0
        self.image = self.frames[self.animation_index]
        self.rect = self.image.get_rect(midbottom = (randint(1200, 1400), y_pos))

    def animation_state(self):
        self.animation_index += 0.1
        if self.animation_index >= len(self.frames):
            self.animation_index = 0
        self.image = self.frames[int(self.animation_index)]

    def update(self):
        self.animation_state()
        self.rect.x -= 8
        self.destroy()

    def destroy(self): 
        if self.rect.x <= -200: 
            self.kill()
        
def display_score():
	current_time = int(pygame.time.get_ticks() / 1000) - start_time
	score_surf = font.render(f'Score: {current_time}',False,(64,64,64))
	score_rect = score_surf.get_rect(center = SCORE_POSITION)
	screen.blit(score_surf,score_rect)
	return current_time

def collision_sprite():
    player_rect = player_group.sprite.rect.inflate(-100, -100)

    for obstacle in obstacle_group:
        obstacle_rect = obstacle.rect.inflate(-100, -100)
        if player_rect.colliderect(obstacle_rect):
            obstacle_group.empty()
            return False

    return True    

def display_title():
    title_pos = (540,50)
    title_surf = font_bigger.render("Mexican Jumper", False, (64,64,64))
    title_rect = title_surf.get_rect(center=title_pos)

    enter_pos = (540,670)
    enter_surf = font_bigger.render("Press enter to start", False, (64,64,64))
    enter_rect = enter_surf.get_rect(center=enter_pos)

    character_pos = (540,360)
    character_image = pygame.image.load("graphics/character/character_1.png")
    character_image = pygame.transform.scale(character_image, (500,500)).convert_alpha()
    character_rect = character_image.get_rect(center=character_pos)

    screen.blit(title_surf, title_rect)
    screen.blit(enter_surf, enter_rect)
    screen.blit(character_image, character_rect)


# VARIABLES
game_active = False
clock = pygame.time.Clock()
font = pygame.font.Font(None, 50)
font_bigger = pygame.font.Font(None, 80)
start_time = 0

# TIMER
obstacle_timer = pygame.USEREVENT + 1
pygame.time.set_timer(obstacle_timer,1500)

# SCREEN
screen = pygame.display.set_mode(SCREEN_SIZE)
pygame.display.set_caption("Mexican Jumper")

# BACKGROUND
original_background_img = pygame.image.load("graphics/background/desert_v2.png")
background_img_size = SCREEN_SIZE
background_img = pygame.transform.scale(original_background_img, background_img_size)

# GROUPS
player_group = pygame.sprite.GroupSingle()
player_group.add(Player())

obstacle_group = pygame.sprite.Group()

# GAME LOOP
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

        if game_active:
            if event.type == obstacle_timer:
                obstacle_group.add(Obstacle(choice(["bird", "cactus", "cactus", "cactus", "turtle", "turtle", "turtle"])))
        else:
             if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                  game_active = True
                  start_time = int(pygame.time.get_ticks() / 1000)
    

    if game_active:
        # BG IMG
        screen.blit(background_img, (0,0))
        score = display_score()

        # PLAYER
        player_group.draw(screen)
        player_group.update()

        # OBSTACLE
        obstacle_group.draw(screen)
        obstacle_group.update()

        game_active = collision_sprite()
    
    else:
        screen.fill((240,204,60))    
        display_title()
    pygame.display.update()
    clock.tick(FPS)
