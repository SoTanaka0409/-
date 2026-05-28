#include "CapsuleCollider.h"
#include "SphereColliderh.h"
#include "Object3D.h"

CapsuleCollider::CapsuleCollider(Object3D* parent, VECTOR pos1, VECTOR pos2, float radius)
	: Collider(parent)
{
	mvPosition = pos1;
	mvPosition2 = pos2;
	mfRadius = radius;
}

CapsuleCollider::~CapsuleCollider()
{

}

void CapsuleCollider::Update(Collider* check)
{
	if (check != nullptr)
	{
		// ‘Šè‚ªƒJƒvƒZƒ‹‚Ìê‡
		CapsuleCollider* capsule = dynamic_cast<CapsuleCollider*>(check);
		
		if (capsule != nullptr)
		{
			bool isHit = HitCheck_Capsule_Capsule(
				this->mvPosition,
				this->mvPosition2,
				this->mfRadius,
				capsule->mvPosition,
				capsule->mvPosition2,
				capsule->mfRadius
			);

			HitCheck(check, isHit);
		}
	}
	if (check != nullptr)
	{
		SphereCollider* sphere = dynamic_cast<SphereCollider*>(check);
		if (sphere != nullptr)
		{
			bool isHit = HitCheck_Sphere_Capsule(
				sphere->mvPosition,
				sphere->mfRadius,
				this->mvPosition,
				this->mvPosition2,
				this->mfRadius

			);
			HitCheck(this, isHit);
		}
	}
}

void CapsuleCollider::Draw()
{
	DrawCapsule3D(
		mvPosition,
		mvPosition2,
		mfRadius,
		8,
		GetColor(255, 255, 255),
		GetColor(255, 255, 255),
		false
	);
}


