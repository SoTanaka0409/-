#pragma once
#include "GameObject.h"

enum class EnemyState {
    NORMAL,
    SUCKED,
    THROWN
};

class Enemy : public GameObject {
private:
    EnemyState state;
    float speed;
    float radius;
    VECTOR targetPos;

public:
    Enemy(VECTOR spawnPos);
    virtual ~Enemy() = default;

    void Update() override;
    void Draw() override;

    void SetState(EnemyState newState) { state = newState; }
    EnemyState GetState() const { return state; }
};
