#pragma once
#include <DxLib.h>

class GameObject {
protected:
    VECTOR pos;
    bool isActive;

public:
    GameObject() : pos(VGet(0, 0, 0)), isActive(true) {}
    virtual ~GameObject() = default;

    virtual void Update() = 0;
    virtual void Draw() = 0;

    bool IsActive() const { return isActive; }
    void Destroy() { isActive = false; }
    
    VECTOR GetPos() const { return pos; }
    void SetPos(VECTOR p) { pos = p; }
};
