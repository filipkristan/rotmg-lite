#include <raylib.h>
#include "Animation.hpp"

Animation playerAnimation = (Animation){
    .first = 0,
    .last = 3,
    .current = 0,
    .speed = 0.1,
    .durationLeft = 0.1
};

void updateAnimation(Animation *self, float dt) {
    self->durationLeft -= dt;
    if (self->durationLeft <= 0.0) {
        self->durationLeft = self->speed;
        self->current++;
    }
    if (self->current > self->last) {
        self->current = self->current;
    }
}

Rectangle AnimationFrame(Animation *self, int numberOfFramesPerRow, bool rotateLeft) {
    int multiplier;
    if (!rotateLeft == true) {
        multiplier = 1;
    } else {
        multiplier = -1;
    }
    int x = (self->current % numberOfFramesPerRow) * 8;
    int y = (self->current / numberOfFramesPerRow) * 8;

    return (Rectangle){
        .x = (float) x,
        .y = (float) y,
        .width = (float) multiplier * 8,
        .height = 8
    };
}
