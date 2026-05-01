#ifndef ROTMG_INVENTORY_H
#define ROTMG_INVENTORY_H
#include <raylib.h>
#include <vector>
#include "TextureDeclarations.hpp"
#include "Tilemap.hpp"

struct Item;
extern std::vector<Item> inventory;
extern std::vector<Tiles> tiles;;

enum ItemType {
    NONE = 0,
    BOWT0 = 1,
    BOWT1 = 2,
    BOWT2 = 3,
    BOWT3 = 4,
    BOWT4 = 5,
    BOWT5 = 6,
    BOWT6 = 7,
    BOWT7 = 8,
    BOWT8 = 9,
    BOWT9 = 10,
    BOWT10 = 11,
    BOWT11 = 12,
    BOWT12 = 13,
    DOOMBOW = 14,
    CORALBOW = 15,
    QUIVERT0 = 16,
    QUIVERT1 = 17,
    QUIVERT2 = 18,
    QUIVERT3 = 19,
    QUIVERT4 = 20,
    QUIVERT5 = 21,
    QUIVERT6 = 22,
    LEATHERARMORT1 = 23,
    LEATHERARMORT2 = 24,
    LEATHERARMORT3 = 25,
    LEATHERARMORT4 = 26,
    LEATHERARMORT5 = 27,
    LEATHERARMORT6 = 28,
    LEATHERARMORT7 = 29,
    LEATHERARMORT8 = 30,
    LEATHERARMORT9 = 31,
    LEATHERARMORT10 = 32,
    LEATHERARMORT11 = 33,
    LEATHERARMORT12 = 34,
    LEATHERARMORT13 = 35,
    CORALARMOR = 36,
    T1RING = 37,
    T2RING = 38,
    T3RING = 39,
    T4RING = 40,
    T5RING = 41
};

enum itemVariant {
    BOW,
    QUIVER,
    ARMOR,
    RING
};

struct Item {
    ItemType type;
    int id;
    Color color;
    Texture2D texture;
    itemVariant variant;
    int damage;
    int shots;
    int shotangle;
    float rateoffire;
    int texturerotation;
    Texture2D projectiletexture;
    int manaCost;

    Item() {
        type = NONE;
        id = 0;
        color = WHITE;
    }

    Item(ItemType t) : type(t) {
        {
            switch (type) {
                case NONE: id = 0;
                    color = WHITE;
                    shots = 0;
                    shotangle = 0;
                    break;
                case BOWT0:
                    id = 1;
                    color = ORANGE;
                    texture = bowt0;
                    variant = BOW;
                    shots = 1;
                    damage = 25;
                    texturerotation = 45;
                    projectiletexture = greenarrowprojectiletexture;
                    break;
                case BOWT1:
                    id = 2;
                    color = PURPLE;
                    texture = bowt1;
                    variant = BOW;
                    shots = 1;
                    damage = 30;
                    texturerotation = 45;
                    projectiletexture = greenarrowprojectiletexture;
                    break;
                case BOWT2:
                    id = 3;
                    color = ORANGE;
                    texture = bowt2;
                    variant = BOW;
                    shots = 1;
                    damage = 35;
                    texturerotation = 0;
                    projectiletexture = crossbowboltarrowprojectiletexture;
                    break;
                case BOWT3:
                    id = 4;
                    color = PURPLE;
                    texture = bowt3;
                    variant = BOW;
                    shots = 1;
                    damage = 40;
                    texturerotation = 45;
                    projectiletexture = greenarrowprojectiletexture;
                    break;
                case BOWT4:
                    id = 5;
                    color = ORANGE;
                    texture = bowt4;
                    variant = BOW;
                    shots = 1;
                    damage = 50;
                    texturerotation = 45;
                    projectiletexture = greenarrowprojectiletexture;
                    break;
                case BOWT5:
                    id = 6;
                    color = PURPLE;
                    texture = bowt5;
                    variant = BOW;
                    shots = 1;
                    damage = 55;
                    texturerotation = 0;
                    projectiletexture = redfirearrowprojectiletexture;
                    break;
                case BOWT6:
                    id = 7;
                    color = ORANGE;
                    texture = bowt6;
                    variant = BOW;
                    shots = 2;
                    damage = 40;
                    texturerotation = 45;
                    projectiletexture = bluearrowprojectiletexture;
                    break;
                case BOWT7:
                    id = 8;
                    color = PURPLE;
                    texture = bowt7;
                    variant = BOW;
                    shots = 1;
                    damage = 60;
                    texturerotation = 0;
                    projectiletexture = heavycrossbowboltarrowprojectiletexture;
                    break;
                case BOWT8:
                    id = 9;
                    color = ORANGE;
                    texture = bowt8;
                    variant = BOW;
                    shots = 3;
                    damage = 50;
                    texturerotation = 45;
                    projectiletexture = goldarrowprojectiletexture;
                    break;
                case BOWT9:
                    id = 10;
                    color = PURPLE;
                    texture = bowt9;
                    variant = BOW;
                    shots = 3;
                    damage = 52;
                    texturerotation = 45;
                    projectiletexture = greenarrowprojectiletexture;
                    break;
                case BOWT10:
                    id = 11;
                    color = ORANGE;
                    texture = bowt10;
                    variant = BOW;
                    shots = 3;
                    damage = 55;
                    texturerotation = 45;
                    projectiletexture = bluearrowprojectiletexture;
                    break;
                case BOWT11:
                    id = 12;
                    color = PURPLE;
                    texture = bowt11;
                    variant = BOW;
                    shots = 3;
                    shotangle = 9;
                    damage = 57;
                    texturerotation = 45;
                    projectiletexture = redfirearrowprojectiletexture;
                    break;
                case BOWT12:
                    id = 13;
                    color = ORANGE;
                    texture = bowt12;
                    variant = BOW;
                    shots = 3;
                    shotangle = 7;
                    damage = 60;
                    texturerotation = 45;
                    projectiletexture = bluearrowprojectiletexture;
                    break;
                case CORALBOW:
                    id = 14;
                    color = PURPLE;
                    texture = coralbow;
                    variant = BOW;
                    shots = 2;
                    shotangle = 9;
                    damage = 70;
                    texturerotation = 45;
                    projectiletexture = coralarrowprojectiletexture; // change to coral
                    break;
                case DOOMBOW:
                    id = 15;
                    color = PURPLE;
                    texture = doombow;
                    variant = BOW;
                    shots = 1;
                    shotangle = 0;
                    damage = 450;
                    texturerotation = 45;
                    projectiletexture = blackarrowprojectiletexture;
                    break;
                case QUIVERT0:
                    id = 16;
                    color = PURPLE;
                    texture = quivert0texture;
                    variant = QUIVER;
                    shots = 1;
                    shotangle = 0;
                    manaCost = 50;
                    break;
                case QUIVERT1:
                    id = 17;
                    color = PURPLE;
                    texture = quivert1texture;
                    variant = QUIVER;
                    shots = 1;
                    shotangle = 0;
                    manaCost = 55;
                    break;
                case QUIVERT2:
                    id = 18;
                    color = PURPLE;
                    texture = quivert2texture;
                    variant = QUIVER;
                    shots = 1;
                    shotangle = 0;
                    manaCost = 60;
                    break;
                case QUIVERT3:
                    id = 19;
                    color = PURPLE;
                    texture = quivert3texture;
                    variant = QUIVER;
                    shots = 1;
                    shotangle = 0;
                    manaCost = 65;
                    break;
                case QUIVERT4:
                    id = 20;
                    color = PURPLE;
                    texture = quivert4texture;
                    variant = QUIVER;
                    shots = 1;
                    shotangle = 0;
                    manaCost = 70;
                    break;
                case QUIVERT5:
                    id = 21;
                    color = PURPLE;
                    texture = quivert5texture;
                    variant = QUIVER;
                    shots = 1;
                    shotangle = 0;
                    manaCost = 75;
                    break;
                case QUIVERT6:
                    id = 22;
                    color = PURPLE;
                    texture = quivert6texture;
                    variant = QUIVER;
                    shots = 1;
                    shotangle = 0;
                    manaCost = 75;
                    break;
                case LEATHERARMORT1:
                    id = 23;
                    color = PURPLE;
                    texture = t1leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT2:
                    id = 24;
                    color = PURPLE;
                    texture = t2leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT3:
                    id = 25;
                    color = PURPLE;
                    texture = t3leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT4:
                    id = 26;
                    color = PURPLE;
                    texture = t4leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT5:
                    id = 27;
                    color = PURPLE;
                    texture = t5leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT6:
                    id = 28;
                    color = PURPLE;
                    texture = t6leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT7:
                    id = 29;
                    color = PURPLE;
                    texture = t7leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT8:
                    id = 30;
                    color = PURPLE;
                    texture = t8leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT9:
                    id = 31;
                    color = PURPLE;
                    texture = t9leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT10:
                    id = 32;
                    color = PURPLE;
                    texture = t10leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT11:
                    id = 33;
                    color = PURPLE;
                    texture = t11leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT12:
                    id = 34;
                    color = PURPLE;
                    texture = t12leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case LEATHERARMORT13:
                    id = 35;
                    color = PURPLE;
                    texture = t13leatherarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case CORALARMOR:
                    id = 36;
                    color = PURPLE;
                    texture = coralarmortexture;
                    variant = ARMOR;
                    shots = 0;
                    shotangle = 0;
                    break;
                case T1RING:
                    id = 37;
                    color = PURPLE;
                    texture = t1ringtexture;
                    variant = RING;
                    shots = 0;
                    shotangle = 0;
                    break;
                case T2RING:
                    id = 38;
                    color = PURPLE;
                    texture = t2ringtexture;
                    variant = RING;
                    shots = 0;
                    shotangle = 0;
                    break;
                case T3RING:
                    id = 39;
                    color = PURPLE;
                    texture = t3ringtexture;
                    variant = RING;
                    shots = 0;
                    shotangle = 0;
                    break;
                case T4RING:
                    id = 40;
                    color = PURPLE;
                    texture = t4ringtexture;
                    variant = RING;
                    shots = 0;
                    shotangle = 0;
                    break;
                case T5RING:
                    id = 41;
                    color = PURPLE;
                    texture = t5ringtexture;
                    variant = RING;
                    shots = 0;
                    shotangle = 0;
                    break;
                default:
                    id = 0;
                    color = WHITE;
                    shots = 0;
                    shotangle = 0;
            }
        }
    };
};

void updateInventoryLogic();

void drawInventory();

#endif //ROTMG_INVENTORY_H
