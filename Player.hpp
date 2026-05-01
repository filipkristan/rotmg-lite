#ifndef PLAYER_EXPERIMENT_PLAYER_HH
#define PLAYER_EXPERIMENT_PLAYER_HH
#include <raylib.h>
#include <string>

struct Player {
    float x;
    float y;
    float width;
    float height;
    float speed;
    float health;
    float maxHealth;
    float hp;
    float level;
    float xp;
    float mana;
    float maxMana;
    float dex;
    float spd;
    float atk;
    float vit;
    float wiz;
    float def;
    float fame;
    int placeTileID;
    bool isEditing;
    bool alive;
    std::string name;
    Vector2 pos;
    Vector2 velocity;
    Vector2 origin;
    Rectangle rect;
    Image image;
    Texture2D texture;
};

extern Player player;
extern Camera2D camera;

void initPlayer();

void updatePlayer(float dt);

void drawPlayer();

void initPlayerCamera();

void updatePlayerCamera();

void movePlayerUp(float dt);

void movePlayerDown(float dt);

void movePlayerLeft(float dt);

void movePlayerRight(float dt);

#endif //PLAYER_EXPERIMENT_PLAYER_HH
