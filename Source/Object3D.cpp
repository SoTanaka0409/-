#include"Object3D.h"
#include"Master.h"
#include"ObjectManager.h"
#include"Scene.h"
#include"CapsuleCollider.h"



Object3D::Object3D(VECTOR initPos)
	:mvPosition(initPos)
	, mpCapsuleCollider(nullptr)
	, mvRotation(VGet(0.0f, 0.0f, 0.0f))
	, mbDeleteFlag(false)
	, mnTag(Tag3D::None3D)
	,mbDrawFlag(true)
	,mfRadius(0)
	
{
	//現在のシーンのobjectManagerに自信（this)を追加する
	Master::mpSceneManager->GetCurrentScene()->GetObjectManager()->AddObject(this);
	mpCapsuleCollider = new CapsuleCollider(this,initPos,initPos,0);
}

//デストラクタ
Object3D::~Object3D()
{
	if (mpCapsuleCollider != nullptr)
	{
		delete mpCapsuleCollider;
		mpCapsuleCollider = nullptr;
	}
}
//描画wwwwwwwwwwwwwww
void Object3D::Draw()
{

}

//更新
void Object3D::Update()
{

}

void Object3D::OnEnter(Collider* collider, Collider* check)
{

}

void Object3D::OnTrigger(Collider* collider, Collider* check)
{

}

void Object3D::OnExit(Collider* collider, Collider* check)
{

}

