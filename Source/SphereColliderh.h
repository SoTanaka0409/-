#pragma once
#include"dxlib.h"
#include"Collider.h"
#include"Object3D.h"

class SphereCollider :public Collider
{
public:
	SphereCollider(Object3D* parent,VECTOR pos,float r);

	virtual ~SphereCollider();

	void Update(Collider* collider);

	void Draw();


};