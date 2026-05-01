#ifndef ROTMG_BULLETS_HPP
#define ROTMG_BULLETS_HPP
#include <raylib.h>
#include <vector>

struct Bullets {
    Texture2D texture;
    Vector2 pos;
    Vector2 velocity;
    Rectangle rect;
    float duration = 1.0f;
    float width;
    float height;
    float speed;
    float timer;
    float delay;
    float rotation;
    float damage;
    int type;
    bool alive;
};

extern Bullets playerProjectile;
extern std::vector<Bullets> playerProjectiles;

void shootBullet(Vector2 origin, Vector2 target, int count, int spreadAngle, Vector2 offset,
                 std::vector<Bullets> &projectilesArray, Bullets &bullet, int damage, int texturerotate,
                 Texture2D projectiletexture, bool isPlayer);

#endif //ROTMG_BULLETS_HPP
