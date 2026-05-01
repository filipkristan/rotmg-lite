#ifndef ROTMG_TESTENTITY_HPP
#define ROTMG_TESTENTITY_HPP
#include <raylib.h>
#include <vector>
#include "Bullets.hpp"

extern Bullets enemyBullet;
extern std::vector<Bullets> enemyBullets;;

enum Gods {
    MEDUSA,
    GHOST_GOD,
    SPRITE_GOD,
    RED_DEMON,
    WHITE_DEMON,
    FLYING_BRAIN,
};

class TestEntity {
public:
    Vector2 pos = {4096, 4096};
    float height = 64;
    float width = 64;
    float health = 1000;
    bool alive = true;
    Rectangle rect = {pos.x, pos.y, width, height};
    Image image;
    Texture2D texture;

    TestEntity(Gods type, Vector2 position);
};

void drawtestentities(float dt);

void updatetestentities(float dt);

extern std::vector<TestEntity> testEntities;

#endif //ROTMG_TESTENTITY_HPP
