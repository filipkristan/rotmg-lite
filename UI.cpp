#include <raylib.h>
#include "UI.hpp"
#include "Player.hpp"

float cursorSize = 32.0;
Vector2 cursorPos = {400 - cursorSize / 2, 300 - cursorSize / 2};
Texture2D cursorTexture;
Texture2D placeholder2;
Font fontTtf;
Font rotmgFontItalic;
Font rotmgFontLight;

void createInventorySlot(float x, float y) {
    DrawRectangle(x, y, 40, 40, {84, 84, 84, 255});
}

void initCursorAndPlaceholders() {
    cursorTexture = LoadTexture("../assets/cursors.png");
    placeholder2 = LoadTexture("../assets/players.png");
    fontTtf = LoadFontEx("../assets/fonts/Myriad Pro Bold.ttf", 64, 0, 250);
    rotmgFontItalic = LoadFontEx("../assets/fonts/Myriad Pro Italic.ttf", 64, 0, 250);
    rotmgFontLight = LoadFontEx("../assets/fonts/Myriad Pro Semibold.ttf", 64, 0, 250);
}

void drawCursor() {
    cursorPos = GetMousePosition();
    Rectangle sourceRec = {0.0f, 0.0f, cursorSize, cursorSize};
    Rectangle destRec = {cursorPos.x - cursorSize / 2, cursorPos.y - cursorSize / 2, cursorSize, cursorSize};
    DrawTexturePro(cursorTexture, sourceRec, destRec, (Vector2){0, 0}, 0.0f, WHITE);
}

void drawPlayerHUD() {
    // HUD
    DrawLine(800 - 200, 0, 800 - 200, 600, BLACK);
    DrawRectangle(800 - 200, 0, 200, 600, Color{54, 54, 54, 255});

    // Map
    DrawRectangle(800 - 200 + 4, 4, 192, 192, BLACK);

    // ign
    DrawTextEx(rotmgFontLight, player.name.c_str(), (Vector2){800 - 200 + 34, 208.0f}, 16, 0, WHITE);

    // player icon next to name
    DrawTexturePro(placeholder2, {0, 24, 8, 8}, {610 - 1, 206 - 1, 16, 16}, {0, 0}, 0, BLACK);
    DrawTexturePro(placeholder2, {0, 24, 8, 8}, {610 + 1, 206 + 1, 16, 16}, {0, 0}, 0, BLACK);
    DrawTexturePro(placeholder2, {0, 24, 8, 8}, {610 + 1, 206 - 1, 16, 16}, {0, 0}, 0, BLACK);
    DrawTexturePro(placeholder2, {0, 24, 8, 8}, {610 - 1, 206 + 1, 16, 16}, {0, 0}, 0, BLACK);
    DrawTexturePro(placeholder2, {0, 24, 8, 8}, {610, 206, 16, 16}, {0, 0}, 0, WHITE);

    // Player LEVEL/HP/FAME, HP, MANA
    DrawRectangle(800 - 200 + 12, 230, 176, 16, {84, 84, 84, 255}); // empty lvl bar
    DrawRectangle(800 - 200 + 12, 230, 176, 16, {90, 128, 37, 255}); // xp bar
    DrawTextEx(fontTtf, TextFormat("Lvl %d", player.level), (Vector2){800 - 200 + 16, 230 + 2}, 14, 0, WHITE);

    DrawRectangle(800 - 200 + 12, 230 + 16 + 8, 176, 16, {84, 84, 84, 255}); // empty hp bar
    DrawRectangle(800 - 200 + 12, 230 + 16 + 8, (player.health / player.maxHealth) * 176, 16,
                  {224, 52, 52, 255}); // hp bar
    DrawTextEx(fontTtf, "HP", (Vector2){800 - 200 + 16, 230 + 16 + 8 + 2}, 14, 0, WHITE);

    DrawRectangle(800 - 200 + 12, 230 + 16 + 8 + 16 + 8, 176, 16, {84, 84, 84, 255}); // empty mana bar
    DrawRectangle(800 - 200 + 12, 230 + 16 + 8 + 16 + 8, (player.mana / player.maxMana) * 176, 16, {96, 132, 224, 255});
    // mana bar
    DrawTextEx(fontTtf, "MP", (Vector2){800 - 200 + 16, 230 + 16 + 8 + 16 + 8 + 2}, 14, 0, WHITE);

    // player stats
    DrawTextEx(fontTtf, TextFormat("ATK - %d", (int) player.atk),
               (Vector2){600 + 25, 230 + 16 + 8 + 16 + 8 + 20 + 20 - 5}, 10, 2, WHITE); // atk
    DrawTextEx(fontTtf, TextFormat("SPD - %d", (int) player.spd), (Vector2){600 + 25, 230 + 16 + 8 + 16 + 8 + 30 + 20},
               10, 2, WHITE); // spd
    DrawTextEx(fontTtf, TextFormat(" VIT - %d", (int) player.vit),
               (Vector2){600 + 25, 230 + 16 + 8 + 16 + 8 + 40 + 20 + 5}, 10, 2, WHITE); // vit
    DrawTextEx(fontTtf, TextFormat("DEF - %d", (int) player.def),
               (Vector2){600 + 125, 230 + 16 + 8 + 16 + 8 + 20 + 20 - 5}, 10, 2, WHITE); // def
    DrawTextEx(fontTtf, TextFormat("DEX - %d", (int) player.dex), (Vector2){600 + 125, 230 + 16 + 8 + 16 + 8 + 30 + 20},
               10, 2, WHITE); // dex
    DrawTextEx(fontTtf, TextFormat("WIZ - %d", (int) player.wiz),
               (Vector2){600 + 125, 230 + 16 + 8 + 16 + 8 + 40 + 20 + 5}, 10, 2, WHITE); // wis

    // player inventory slots
    createInventorySlot(600 + 14, 600 - 108 - 40 - (40 + 4) * 2);
    createInventorySlot(600 + 14 + (40 + 4) * 1, 600 - 108 - 40 - (40 + 4) * 2);
    createInventorySlot(600 + 14 + (40 + 4) * 2, 600 - 108 - 40 - (40 + 4) * 2);
    createInventorySlot(600 + 14 + (40 + 4) * 3, 600 - 108 - 40 - (40 + 4) * 2);

    createInventorySlot(600 + 14, 600 - 108 - 40 - (40 + 4) * 1);
    createInventorySlot(600 + 14 + (40 + 4) * 1, 600 - 108 - 40 - (40 + 4) * 1);
    createInventorySlot(600 + 14 + (40 + 4) * 2, 600 - 108 - 40 - (40 + 4) * 1);
    createInventorySlot(600 + 14 + (40 + 4) * 3, 600 - 108 - 40 - (40 + 4) * 1);

    createInventorySlot(600 + 14, 600 - 108 - 40);
    createInventorySlot(600 + 14 + (40 + 4) * 1, 600 - 108 - 40);
    createInventorySlot(600 + 14 + (40 + 4) * 2, 600 - 108 - 40);
    createInventorySlot(600 + 14 + (40 + 4) * 3, 600 - 108 - 40);
}

void displayDeathScreen() {
    if (!player.alive) {
        DrawRectangle(0, 0, 800, 600, BLACK);
    }
}
