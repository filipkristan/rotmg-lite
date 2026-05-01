#include "TestEntity.hpp"
#include "Bullets.hpp"
#include "Inventory.hpp"
#include "Player.hpp"

std::vector<TestEntity> testEntities;

TestEntity::TestEntity(Gods type, Vector2 position) {
    Image REDDEMOONIMAGE = LoadImage("../assets/gods.png");
    Texture2D REDDEMOONTEXTURE;
    pos = position;
    switch (type) {
        case MEDUSA:
            width = 96;
            height = 96;
            break;
        case GHOST_GOD:
            width = 96;
            height = 96;
            break;
        case RED_DEMON:
            width = 96;
            height = 96;
            ImageCrop(&REDDEMOONIMAGE, {0, 0, 16, 16});
            ImageResizeNN(&REDDEMOONIMAGE, width, height);
            REDDEMOONTEXTURE = LoadTextureFromImage(REDDEMOONIMAGE);
            SetTextureFilter(REDDEMOONTEXTURE, TEXTURE_FILTER_POINT);
            texture = REDDEMOONTEXTURE;
            alive = true;
            break;
        case WHITE_DEMON:
            width = 96;
            height = 96;
            break;
        case FLYING_BRAIN:
            width = 96;
            height = 96;
            break;
        default:
            break;
    }
}

void updatetestentities(float dt) {
    for (auto enemy: testEntities) {
        if (enemy.alive && player.alive) {
            enemy.rect = {enemy.pos.x, enemy.pos.y, enemy.width, enemy.height};
            static float elapsedTime = 0.0f;
            elapsedTime += dt;
            if (elapsedTime >= 0.1) {
                elapsedTime = 0.0f;
                shootBullet(enemy.pos, player.pos, 2, 0, {32, 32}, enemyBullets, enemyBullet, inventory[0].damage,
                            inventory[0].texturerotation, inventory[0].projectiletexture, false);
            }
            if (enemy.health <= 0) {
                enemy.alive = false;
                // remove enemy, buggy
                //std::cout << "removing enemy" << std::endl;
                std::erase_if(testEntities, [](const auto &enemy) {
                    return enemy.alive;
                });
            }
        } else {
        }
    }
    //std::cout << testEntities.size() << std::endl;
}

void drawtestentities(float dt) {
    for (auto enemy: testEntities) {
        if (enemy.alive) {
            DrawTexture(enemy.texture, enemy.pos.x + 1, enemy.pos.y + 1, BLACK);
            DrawTexture(enemy.texture, enemy.pos.x + 1, enemy.pos.y - 1, BLACK);
            DrawTexture(enemy.texture, enemy.pos.x - 1, enemy.pos.y + 1, BLACK);
            DrawTexture(enemy.texture, enemy.pos.x - 1, enemy.pos.y - 1, BLACK);
            DrawTexture(enemy.texture, enemy.pos.x, enemy.pos.y, WHITE);
        } else if (!enemy.alive) {
            DrawText("dead", enemy.pos.x, enemy.pos.y, 10,WHITE);
        }
    }
}
