#include "PlayerProjectiles.hpp"
#include "TestEntity.hpp"
#include <raylib.h>

Texture2D ProjectileTexture01;
Image ProjectileImage01;

void updatePlayerProjectiles(float dt) {
    for (auto &projectile: playerProjectiles) {
        if (projectile.alive) {
            projectile.pos.x += projectile.velocity.x * dt;
            projectile.pos.y += projectile.velocity.y * dt;
            projectile.rect = {projectile.pos.x, projectile.pos.y, projectile.width, projectile.height};
            projectile.timer += dt;
            if (projectile.timer >= projectile.duration) {
                projectile.alive = false;
            } else {
                std::erase_if(playerProjectiles, [](const auto &p) {
                    return !p.alive;
                });
                for (auto &enemy: testEntities) {
                    if (enemy.alive) {
                        if (CheckCollisionRecs(enemy.rect, projectile.rect)) {
                            projectile.alive = false;
                            enemy.health -= projectile.damage;
                        }
                    }
                }
            }
        }
    }
}

void drawPlayerProjectiles() {
    for (auto &projectile: playerProjectiles) {
        Rectangle source = {0.0f, 0.0f, 8.0f, 8.0f};
        Vector2 origin = {40 / 2.0f, 40 / 2.0f};
        Rectangle dest = {
            projectile.pos.x,
            projectile.pos.y,
            40,
            40
        };
        //DrawRectangleRec(projectile.rect, WHITE);
        DrawTexturePro(projectile.texture, source, dest, origin, projectile.rotation, WHITE);
    }
}
