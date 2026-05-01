#include "Enemies.hpp"
#include "Player.hpp"
#include "TestEntity.hpp"
#include "Bullets.hpp"
#include <raylib.h>

void updateEnemyBullets(float dt) {
    for (auto &p: enemyBullets) {
        if (p.alive) {
            p.pos.x += p.velocity.x * dt;
            p.pos.y += p.velocity.y * dt;
            p.rect = {p.pos.x, p.pos.y, p.width, p.height};
            p.timer += dt;
            if (p.timer >= p.duration) {
                p.alive = false;
            }
            if (CheckCollisionRecs(player.rect, p.rect)) {
                p.alive = false;
                player.health -= p.damage;
            }
        } else {
            std::erase_if(enemyBullets, [](const auto &p) {
                return !p.alive;
            });
        }
    }
}

void drawEnemyBullets(float dt) {
    for (auto &p: enemyBullets) {
        Rectangle source = {0.0f, 0.0f, 8.0f, 8.0f};
        Vector2 origin = {48 / 2.0f, 48 / 2.0f};
        Rectangle dest = {p.pos.x, p.pos.y, p.width, p.height};
        DrawTexturePro(p.texture, source, dest, origin, p.rotation, WHITE);
    }
}
