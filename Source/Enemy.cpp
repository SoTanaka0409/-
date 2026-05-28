#include "Enemy.h"
#include <math.h>

Enemy::Enemy(VECTOR spawnPos) {
    pos = spawnPos;
    state = EnemyState::NORMAL;
    speed = 1.0f;
    radius = 8.0f;
    targetPos = VGet(0.0f, 0.0f, 0.0f); // Move towards the core (origin)
}

void Enemy::Update() {
    if (state == EnemyState::NORMAL) {
        // Move towards targetPos
        VECTOR dir = VSub(targetPos, pos);
        float dist = VSize(dir);
        if (dist > 0.0f) {
            dir = VNorm(dir);
            pos = VAdd(pos, VScale(dir, speed));
        }
    }
    // SUCKED and THROWN states will be implemented later
}

void Enemy::Draw() {
    // Draw enemy as a red cube
    VECTOR p1 = VGet(pos.x - radius, pos.y - radius, pos.z - radius);
    VECTOR p2 = VGet(pos.x + radius, pos.y + radius, pos.z + radius);
    DrawCube3D(p1, p2, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
}
