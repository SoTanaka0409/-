#include "Player.h"

Player::Player() {
    pos = VGet(0.0f, 0.0f, 0.0f);
    speed = 5.0f;
    radius = 10.0f;
}

void Player::Update() {
    // Movement handling (using arrow keys or WASD)
    if (CheckHitKey(KEY_INPUT_UP) || CheckHitKey(KEY_INPUT_W)) {
        pos.z += speed;
    }
    if (CheckHitKey(KEY_INPUT_DOWN) || CheckHitKey(KEY_INPUT_S)) {
        pos.z -= speed;
    }
    if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) {
        pos.x -= speed;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) {
        pos.x += speed;
    }
}

void Player::Draw() {
    // Draw player as a green sphere
    DrawSphere3D(pos, radius, 16, GetColor(0, 255, 0), GetColor(0, 255, 0), TRUE);
}
