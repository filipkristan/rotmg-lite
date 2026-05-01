#include "Inventory.hpp"
#include <iostream>
#include <ostream>
#include <raylib.h>
#include <vector>

Vector2 mousePos;
std::vector<Item> inventory(12, Item(NONE));

// item slots
const int slotsPerRow = 4;
const int slotSize = 40;
const int spacing = 4;
const int startX = 614;
const int startY = 364;

int draggedSlot = -1;

void updateInventoryLogic() {
    mousePos = GetMousePosition();

    // drag and drop logic
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        for (int i = 0; i < inventory.size(); i++) {
            Rectangle slotRec = {
                (float) (startX + (i % slotsPerRow) * (slotSize + spacing)),
                (float) (startY + (i / slotsPerRow) * (slotSize + spacing)),
                (float) slotSize, (float) slotSize
            };
            if (CheckCollisionPointRec(mousePos, slotRec) && inventory[i].type != NONE) {
                draggedSlot = i;
                break;
            }
        }
    }

    // slot swap
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && draggedSlot != -1) {
        for (int i = 0; i < inventory.size(); i++) {
            Rectangle slotRec = {
                (float) (startX + (i % slotsPerRow) * (slotSize + spacing)),
                (float) (startY + (i / slotsPerRow) * (slotSize + spacing)),
                (float) slotSize, (float) slotSize
            };
            // swap item depending if its the correct tiype
            if (CheckCollisionPointRec(mousePos, slotRec)) {
                if (inventory[draggedSlot].variant == BOW) {
                    if (i == 0 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
                        if (inventory[i].variant == 0) {
                            std::cout << "MOVING BOW" << std::endl;
                            Item temp = inventory[i];
                            inventory[i] = inventory[draggedSlot];
                            inventory[draggedSlot] = temp;
                            break;
                        }
                    } else {
                        std::cout << "NOT MOVING BOW" << std::endl;
                    }
                }
                if (inventory[draggedSlot].variant == QUIVER) {
                    // SELECTED ITEM IS A QUIVER
                    if (i == 1 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
                        if (inventory[i].variant == 1) {
                            std::cout << "variant is 1" << std::endl;
                            std::cout << "MOVING QUIVER" << std::endl;
                            std::cout << inventory[i].variant << std::endl;
                            Item temp = inventory[i];
                            inventory[i] = inventory[draggedSlot];
                            inventory[draggedSlot] = temp;
                        }

                        break;
                    } else {
                        std::cout << "NOT MOVING QUIVER" << std::endl;
                    }
                }
                if (inventory[draggedSlot].variant == ARMOR) {
                    if (i == 2 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
                        if (inventory[i].variant == 2) {
                            std::cout << "MOVING ARMOR" << std::endl;
                            Item temp = inventory[i];
                            inventory[i] = inventory[draggedSlot];
                            inventory[draggedSlot] = temp;
                            break;
                        }
                    } else {
                        std::cout << "NOT MOVING ARMOR" << std::endl;
                    }
                }
                if (inventory[draggedSlot].variant == RING) {
                    if (i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11) {
                        if (inventory[i].variant == 3) {
                            std::cout << "MOVING RING" << std::endl;
                            Item temp = inventory[i];
                            inventory[i] = inventory[draggedSlot];
                            inventory[draggedSlot] = temp;
                            break;
                        }
                    } else {
                        std::cout << "NOT MOVING RING" << std::endl;
                    }
                }
                {
                    std::cout << "else" << std::endl;
                }
                break;
            }
        }
        draggedSlot = -1;
    }
}

void drawInventory() {
    // slots
    for (int i = 0; i < inventory.size(); i++) {
        float x = startX + (i % slotsPerRow) * (slotSize + spacing);
        float y = startY + (i / slotsPerRow) * (slotSize + spacing);
        // draw the item if the slot is not empty and not being dragged
        if (inventory[i].type != NONE && i != draggedSlot) {
            DrawTextureEx(inventory[i].texture, {x + 5, y + 5}, 0, 4,BLACK);
            DrawTextureEx(inventory[i].texture, {x + 3, y + 3}, 0, 4,BLACK);
            DrawTextureEx(inventory[i].texture, {x + 3, y + 5}, 0, 4,BLACK);
            DrawTextureEx(inventory[i].texture, {x + 5, y + 3}, 0, 4,BLACK);
            DrawTextureEx(inventory[i].texture, {x + 4, y + 4}, 0, 4,WHITE);
        }
    }

    // draw dragged items
    if (draggedSlot != -1) {
        DrawTextureEx(inventory[draggedSlot].texture, {mousePos.x - slotSize / 2 + 1, mousePos.y - slotSize / 2 + 1,},
                      0, 4,BLACK);
        DrawTextureEx(inventory[draggedSlot].texture, {mousePos.x - slotSize / 2 - 1, mousePos.y - slotSize / 2 - 1,},
                      0, 4,BLACK);
        DrawTextureEx(inventory[draggedSlot].texture, {mousePos.x - slotSize / 2 - 1, mousePos.y - slotSize / 2 + 1,},
                      0, 4,BLACK);
        DrawTextureEx(inventory[draggedSlot].texture, {mousePos.x - slotSize / 2 + 1, mousePos.y - slotSize / 2 - 1,},
                      0, 4,BLACK);
        DrawTextureEx(inventory[draggedSlot].texture, {mousePos.x - slotSize / 2, mousePos.y - slotSize / 2,}, 0, 4,
                      WHITE);
    }
}
