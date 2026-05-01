#include "Tilemap.hpp"
#include "Player.hpp"
#include "TextureDeclarations.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

Tiles tile;
std::vector<Tiles> tiles;
Tiles tileChecker;
std::vector<Tiles> tileCheckers;
std::vector<Tiles> visibleTiles;
std::string placeholderLevel = "../level.txt";
std::string abyss = "../abyss.txt";
std::string udl = "../udl.txt";
std::string snakepit = "../snakepit.txt";
std::string spriteworld = "../spriteworld.txt";
std::string level = placeholderLevel;

int blockSize = 48;
// makes find() work on custom struct
bool operator==(const Tiles &a, const Tiles &b) {
    return a.x == b.x && a.y == b.y;
}

void initTiles() {
    sandtiletexture = LoadTexture("../assets/tiles/sand.png");
    watertiletexture = LoadTexture("../assets/tiles/water.png");
    sand2tiletexture = LoadTexture("../assets/tiles/sand2.png");
    water2tiletexture = LoadTexture("../assets/tiles/water2.png");
    udltiletexture = LoadTexture("../assets/tiles/udl.png");
    udl2tiletexture = LoadTexture("../assets/tiles/udl2.png");
    udl3tiletexture = LoadTexture("../assets/tiles/udl3.png");
    abysstexture = LoadTexture("../assets/tiles/abyss.png");
    abyss2texture = LoadTexture("../assets/tiles/abyss2.png");
    abyss3texture = LoadTexture("../assets/tiles/abyss3.png");
    snaketexture = LoadTexture("../assets/tiles/snake.png");
    snake2texture = LoadTexture("../assets/tiles/snake2.png");
    snake3texture = LoadTexture("../assets/tiles/snake3.png");
    treetexture = LoadTexture("../assets/tiles/tree.png");
    tree2texture = LoadTexture("../assets/tiles/tree2.png");
    grasstexture = LoadTexture("../assets/tiles/grass.png");
    grass2texture = LoadTexture("../assets/tiles/grass2.png");
    grass3texture = LoadTexture("../assets/tiles/grass3.png");
    loadLevel(placeholderLevel);
}

void saveLevel(std::string name) {
    std::ofstream outFile(name);
    if (outFile.is_open()) {
        for (const auto &tile: tiles) {
            outFile << tile.x << " " << tile.y << " " << tile.type << "\n";
        }
        outFile.close();
    }
}

void loadLevel(std::string name) {
    std::ifstream inFile(name);
    if (inFile.is_open()) {
        tiles.clear();
        float x, y;
        int type;
        while (inFile >> x >> y >> type) {
            Tiles tile;
            tile.x = x;
            tile.y = y;
            tile.type = type;
            tiles.push_back(tile);
        }
        inFile.close();
        std::cout << "Successfully loaded" << level << std::endl;
    } else {
        std::cout << "Failed to open file: " << level << std::endl;
    }
}

void drawTiles() {
    for (auto &tile: visibleTiles) {
        Texture2D *tempTexture;
        DrawTextureEx(snake2texture, {tile.x, tile.y}, 0, 6, WHITE);
        //DrawText(TextFormat("%d", tile.wall),tile.x,tile.y,10,WHITE);
    }

    int renderdistance = 16;
    tileCheckers.clear();
    for (int i = 0; i < renderdistance; ++i) {
        for (int j = 0; j < renderdistance; j++) {
            int gridX = player.pos.x / 48 - renderdistance / 2;
            int gridY = player.pos.y / 48 - renderdistance / 2;
            int placeX = gridX * 48 + i * 48;
            int placeY = gridY * 48 + j * 48;

            tileChecker.x = placeX;
            tileChecker.y = placeY;
            tileCheckers.push_back(tileChecker);
        }
    }

    visibleTiles.clear();
    for (auto &target: tiles) {
        auto pos_it = std::find(tileCheckers.begin(), tileCheckers.end(), target);

        if (pos_it != tileCheckers.end()) {
            visibleTiles.push_back(target);
        } else {
            //cout << "Position {" << target.x << ", " << target.y << "} does not exist in the array.\n";
        }
    }
    for (auto &loc: visibleTiles) {
        //std::cout << "Tile located at {" << loc.x << ", " << loc.y << "} is visible.\n";
    }
}

void placeTile(int type, Vector2 position, tileVariant variant) {
    tile.type = type;
    tile.width = 48;
    tile.height = 48;
    tile.x = position.x;
    tile.y = position.y;
    tile.type = variant;
    tiles.push_back(tile);
    saveLevel(placeholderLevel);
}
