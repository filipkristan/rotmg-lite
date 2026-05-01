#include "Player.hpp"
#include <raylib.h>
#include <vector>
#include "Animation.hpp"
#include "Bullets.hpp"
#include "Inventory.hpp"

int framesPerRow;

Player player;
Camera2D camera;
PlayerMode playerMode;

Bullets playerProjectile;
std::vector<Bullets> playerProjectiles;

void initPlayer() {
    // player textures
    archer_walking_right = LoadTexture("../assets/archer/walk.png");
    archer_walking_up = LoadTexture("../assets/archer/walk_down.png");
    archer_walking_down = LoadTexture("../assets/archer/walk_up.png");
    archer_shooting_right = LoadTexture("../assets/archer/shoot.png");
    archer_shooting_up = LoadTexture("../assets/archer/shoot_up.png");
    archer_shooting_down = LoadTexture("../assets/archer/shoot_down.png");
    player.texture = archer_walking_down;
    playerMode.shooting = false;
    playerMode.walking = false;
    playerAnimation.rotateLeft = false;
    framesPerRow = 1;

    // player
    player.pos = {4096.0f - 12, 4096.0f - 12 + 128 * 2};
    player.width = 40.0f;
    player.height = 40.0f;
    player.speed = 400.0f;
    player.rect = {player.pos.x, player.pos.y, player.width, player.height};
    player.name = "Yimi";
    player.level = 1;
    player.xp = 0;
    player.health = 750;
    player.maxHealth = 750;
    player.mana = 300;
    player.maxMana = 300;
    player.def = 25;
    player.dex = 50;
    player.vit = 40;
    player.wiz = 50;
    player.atk = 75;
    player.spd = 55;
    player.isEditing = false;
    player.alive = true;
    player.placeTileID = 1;
    player.origin = {player.pos.x + player.width / 2, player.pos.y + player.height / 2};
}

void updatePlayer(float dt) {
    player.origin = {player.pos.x + player.width / 2, player.pos.y + player.height / 2};
    player.rect = {player.pos.x, player.pos.y, player.width, player.height};
    framesPerRow = 1; // moving breaks things
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        playerMode.shooting = true;
    } else {
        playerMode.shooting = false;
    }
    if (IsKeyDown(KEY_W)) {
        movePlayerUp(dt);
    }
    if (IsKeyDown(KEY_A)) {
        movePlayerLeft(dt);
    }
    if (IsKeyDown(KEY_S)) {
        movePlayerDown(dt);
    }
    if (IsKeyDown(KEY_D)) {
        movePlayerRight(dt);
    }
    if (IsKeyPressed(KEY_SPACE)) {
        player.mana -= inventory[1].manaCost;
    }
    // place tiles
    if (player.isEditing == true || IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = GetScreenToWorld2D(GetMousePosition(), camera);
        int gridX = pos.x / 48;
        int gridY = pos.y / 48;
        float placeX = gridX * 48;
        float placeY = gridY * 48;
    }
    if (IsKeyPressed(KEY_X)) {
        if (camera.offset.x == 300.0f && camera.offset.y == 400.0f) {
            camera.offset = (Vector2){300.0f, 300.0f};
        } else {
            camera.offset = (Vector2){300.0f, 400.0f};
        }
    }
    // player shoot projectiles
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && player.isEditing == false || IsKeyPressed(KEY_SPACE)) {
        Vector2 target = GetMousePosition();
        target = GetScreenToWorld2D({target.x, target.y}, camera);
        static float elapsedTime = 0.0f;
        elapsedTime += dt;
        if (elapsedTime >= 0.1) {
            // hardcoded offset
            shootBullet({player.pos.x + player.width / 2, player.pos.y + player.height / 2 - 20 / 2},
                        {target.x, target.y}, (float) inventory[0].shots,
                        (float) inventory[0].shotangle, {0, 0}, playerProjectiles,
                        playerProjectile, inventory[0].damage, inventory[0].texturerotation, inventory[0].
                        projectiletexture, true);
            elapsedTime = 0.0f;
        }
    }
    // check if dead
    if (player.health <= 0) {
        player.alive = false;
    }
}

void drawPlayer() {
    // draw player, player shadow and outline
    DrawCircle(player.pos.x + player.width / 2, player.pos.y + player.height, player.width / 2, Color{0, 0, 0, 20});
    DrawTexturePro(player.texture, AnimationFrame(&playerAnimation, framesPerRow, playerAnimation.rotateLeft),
                   {player.pos.x + 1, player.pos.y - 1, player.height, player.height}, {0, 0}, 0, BLACK);
    DrawTexturePro(player.texture, AnimationFrame(&playerAnimation, framesPerRow, playerAnimation.rotateLeft),
                   {player.pos.x - 1, player.pos.y - 1, player.height, player.height}, {0, 0}, 0, BLACK);
    DrawTexturePro(player.texture, AnimationFrame(&playerAnimation, framesPerRow, playerAnimation.rotateLeft),
                   {player.pos.x - 1, player.pos.y + 1, player.height, player.height}, {0, 0}, 0, BLACK);
    DrawTexturePro(player.texture, AnimationFrame(&playerAnimation, framesPerRow, playerAnimation.rotateLeft),
                   {player.pos.x + 1, player.pos.y + 1, player.height, player.height}, {0, 0}, 0, BLACK);
    DrawTexturePro(player.texture, AnimationFrame(&playerAnimation, framesPerRow, playerAnimation.rotateLeft),
                   {player.pos.x, player.pos.y, player.height, player.height}, {0, 0}, 0, WHITE);
}

void initPlayerCamera() {
    camera = {};
    camera.target = (Vector2){player.pos.x + player.width / 2, player.pos.y + player.height / 2};
    camera.offset = (Vector2){300.0f, 300.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void updatePlayerCamera() {
    camera.target = (Vector2){player.pos.x + player.width / 2, player.pos.y + player.height / 2};
}

void movePlayerUp(float dt) {
    player.pos.y -= player.speed * dt;
    framesPerRow = 3;
    playerMode.walking = true;
    if (playerMode.shooting == false) {
        player.texture = archer_walking_up;
    } else {
        player.texture = archer_shooting_up;
    }
}

void movePlayerDown(float dt) {
    player.pos.y += player.speed * dt;
    playerMode.walking = true;
    framesPerRow = 3;
    if (playerMode.shooting == false) {
        player.texture = archer_walking_down;
    } else {
        player.texture = archer_shooting_down;
    }
}

void movePlayerLeft(float dt) {
    player.pos.x -= player.speed * dt;
    playerMode.walking = true;
    framesPerRow = 3;
    playerAnimation.rotateLeft = true;
    if (playerMode.shooting == false) {
        player.texture = archer_walking_right;
    } else {
        player.texture = archer_shooting_right;
    }
}

void movePlayerRight(float dt) {
    player.pos.x += player.speed * dt;
    playerMode.walking = true;
    framesPerRow = 3;
    playerAnimation.rotateLeft = false;
    if (playerMode.shooting == false) {
        player.texture = archer_walking_right;
    } else {
        player.texture = archer_shooting_right;
    }
}
