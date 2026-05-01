#include "Player.hpp"
#include "Bullets.hpp"
#include <vector>
#include <raymath.h>

Bullets enemyBullet;
std::vector<Bullets> enemyBullets;

void shootBullet(Vector2 origin, Vector2 target, int count, int spreadAngle, Vector2 offset,
                 std::vector<Bullets> &projectilesArray, Bullets &bullet, int damage, int texturerotate,
                 Texture2D projectiletexture, bool isPlayer) {
    float startAngle = -(spreadAngle * (count - 1)) / 2.0f;
    Vector2 direction = Vector2Normalize(Vector2Subtract(target, origin));
    for (int i = 0; i < count; i++) {
        float currentAngle = startAngle + (i * spreadAngle);
        Vector2 rotatedDir = Vector2Rotate(direction, currentAngle * DEG2RAD);
        float angleRad = atan2f(direction.y, direction.x);
        float angleDeg = angleRad * RAD2DEG + texturerotate;
        bullet.width = 32;
        bullet.height = 32;
        bullet.pos = {origin.x + offset.x, origin.y + offset.y};
        bullet.velocity = Vector2Scale(rotatedDir, bullet.speed);
        bullet.alive = true;
        bullet.damage = damage;
        bullet.rotation = angleDeg;
        bullet.timer = 0.0f;
        bullet.duration = 2.0f;
        bullet.rect = {bullet.pos.x, bullet.pos.y, bullet.width, bullet.height};
        bullet.texture = projectiletexture;
        if (isPlayer) {
            bullet.speed = player.dex * 10;
        } else {
            bullet.speed = 300;
        }
        projectilesArray.push_back(bullet);
    }
}

