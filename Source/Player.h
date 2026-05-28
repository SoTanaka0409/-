#pragma once
#include "GameObject.h"

class Player : public GameObject {
private:
    float speed;
    float radius;

public:
    Player();
    virtual ~Player() = default;

    void Update() override;
    void Draw() override;
};
