#ifndef PLAYER_EXPERIMENT_ANIMATION_HH
#define PLAYER_EXPERIMENT_ANIMATION_HH
#include <raylib.h>

typedef struct Animation {
    int up;
    int down;
    int left;
    int right;
    int first;
    int last;
    int current;
    float speed;
    float durationLeft;
    bool rotateLeft;
} Animation;

struct PlayerMode {
    bool shooting;
    bool walking;
};

extern Animation playerAnimation;

void updateAnimation(Animation *self, float dt);

Rectangle AnimationFrame(Animation *self, int numberOfFramesPerRow, bool rotateLeft);

#endif //PLAYER_EXPERIMENT_ANIMATION_HH
