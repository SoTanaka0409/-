#pragma once
#include "Collider.h"
#include"Object3D.h"
class CapsuleCollider : public Collider
{
public:
	CapsuleCollider(Object3D* parent, VECTOR pos1, VECTOR pos2, float radius);
	virtual ~CapsuleCollider();

	void Update(Collider* check) override;
	void Draw() override;

	

	//ww
};