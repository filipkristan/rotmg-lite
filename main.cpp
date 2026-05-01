#include <raylib.h>
#include "Animation.hpp"
#include "Enemies.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "PlayerProjectiles.hpp"
#include "TestEntity.hpp"
#include "Tilemap.hpp"
#include "UI.hpp"
#include "TextureDeclarations.hpp"

int main(void) {
    InitWindow(800, 600, "Realm of the Mad God");
    SetTargetFPS(400);
    float dt;
    HideCursor();
    initTiles();
    initPlayerCamera();
    initPlayer();
    initCursorAndPlaceholders();
    LoadInventoryTextures();
    inventory[6] = Item{LEATHERARMORT13};
    inventory[5] = Item{BOWT12};
    inventory[4] = Item{DOOMBOW};
    inventory[3] = Item{T5RING};
    inventory[2] = Item{CORALARMOR};
    inventory[1] = Item{QUIVERT6};
    inventory[0] = Item{CORALBOW};
    testEntities.push_back(TestEntity(RED_DEMON, {4096, 4096})); // test entity

    while (!WindowShouldClose()) {
        // Update
        dt = GetFrameTime();
        updateAnimation(&playerAnimation, dt);
        updatePlayer(dt);
        updateInventoryLogic();
        updatePlayerCamera();
        updateEnemyBullets(dt);
        updatePlayerProjectiles(dt);
        updatetestentities(dt);
        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
        drawTiles();
        drawPlayerProjectiles();
        drawPlayer();
        drawtestentities(dt);
        drawEnemyBullets(dt);
        EndMode2D();
        drawPlayerHUD();
        drawInventory();
        drawCursor();
        displayDeathScreen();
        DrawFPS(10, 10);
        EndDrawing();
    }
    saveLevel(placeholderLevel);
    CloseWindow();

    return 0;
}
