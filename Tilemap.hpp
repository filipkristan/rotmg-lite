#ifndef ROTMG_TILEMAP_HH
#define ROTMG_TILEMAP_HH
#include <raylib.h>
#include <string>
#include "TextureDeclarations.hpp"
#define BLOCK_SIZE = 48

extern std::string placeholderLevel;

enum tileVariant {
    NOTILE,
    SAND,
    SAND2,
    WATER,
    WATER2,
    ABYSS,
    ABYSS2,
    ABYSS3,
    SNAKE,
    SNAKE2,
    SNAKE3,
    TREE,
    TREE2,
    UDL,
    UDL2,
    UDL3,
    GRASS,
    GRASS2,
    GRASS3,
};

struct Tiles {
    Image image;
    Texture2D texture;
    float x = 0;
    float y = 0;
    bool alive = true;
    bool wall = false;
    float width = 48;
    float height = 48;
    int type = NOTILE;
    Rectangle rect;
    Color color;
    bool isInViewArea = false;

    Tiles() {
    }

    Tiles(float x, float y, tileVariant t) : type(t) {
        switch (type) {
            case NOTILE:
                color = WHITE;
                break;
            case SAND:
                this->x = x;
                this->y = y;
                texture = sandtiletexture;
                break;
            case SAND2:
                this->x = x;
                this->y = y;
                texture = sand2tiletexture;
                break;
            case WATER:
                this->x = x;
                this->y = y;
                texture = watertiletexture;
                break;
            case WATER2:
                this->x = x;
                this->y = y;
                texture = water2tiletexture;
                break;
            case ABYSS:
                this->x = x;
                this->y = y;
                texture = abysstexture;
                break;
            case ABYSS2:
                this->x = x;
                this->y = y;
                texture = abyss2texture;
                break;
            case ABYSS3:
                this->x = x;
                this->y = y;
                texture = abyss3texture;
                wall = true;
                break;
            case SNAKE:
                this->x = x;
                this->y = y;
                texture = snaketexture;
                break;
            case SNAKE2:
                this->x = x;
                this->y = y;
                texture = snake2texture;
                break;
            case SNAKE3:
                this->x = x;
                this->y = y;
                texture = snake3texture;
                wall = true;
                break;
            case TREE:
                this->x = x;
                this->y = y;
                texture = treetexture;
                wall = true;
                break;
            case TREE2:
                this->x = x;
                this->y = y;
                texture = tree2texture;
                wall = true;
                break;
            case UDL:
                this->x = x;
                this->y = y;
                texture = udltiletexture;
                break;
            case UDL2:
                this->x = x;
                this->y = y;
                texture = udl2tiletexture;
                break;
            case UDL3:
                this->x = x;
                this->y = y;
                texture = udl3tiletexture;
                wall = true;
                break;
            case GRASS:
                this->x = x;
                this->y = y;
                texture = grasstexture;
                break;
            case GRASS2:
                this->x = x;
                this->y = y;
                texture = grass2texture;
                break;
            case GRASS3:
                this->x = x;
                this->y = y;
                texture = grass3texture;
                wall = true;
                break;
            default:
                color = WHITE;
        }
    }
};

void placeTile(int type, Vector2 position, tileVariant variant);

void initTiles();

void drawTiles();

void saveLevel(std::string name);

void loadLevel(std::string name);

#endif //ROTMG_TILEMAP_HH
