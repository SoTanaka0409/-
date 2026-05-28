#pragma once
#include"DxLib.h"
#include<string>

class Collider;

class CapsuleCollider;

class Object3D
{
public:
	enum Tag3D
	{
		None3D,
		Tag3D_Stage,
		Tag3D_player,
		Tag3D_Enemy,
		Tag3D_Cow,
		Tag3D_Wall,
		Tag3D_boss,
		Tag3D_Bait,
		Tag3D_Animal
		//Tag3D_charactor=3600,
		//Tag3D_Object=3900,
	};

	// ★New!! Zソート用★
public: // ソート関数定義
	//
	// Zソート用の設定
	void SetCameraDistance(float distance) { mfCurrentCameraDistance = distance; }

	// カメラ距離を基準にソートするためのオペレーター
	// note: カメラとの距離が離れるほどリストの手前に来るようにする（先に描画したい）
	struct CompareZOrder {
		bool operator()(Object3D* a, Object3D* b) const {
			return a->mfCurrentCameraDistance > b->mfCurrentCameraDistance;
		}
	};



public:
	Object3D(VECTOR initPos);

	virtual ~Object3D();

	virtual void Update();

	virtual void Draw();

	virtual void OnEnter(Collider* collider, Collider* check);
	virtual void OnTrigger(Collider* collider, Collider* check);
	virtual void OnExit(Collider* collider, Collider* check);
	//virtual void Callback() = 0;


public://ゲッター、セッターw
	void SetPosition(VECTOR pos) { mvPosition = pos; };
	VECTOR GetPosition() { return mvPosition; }

	void SetOldPosition(VECTOR pos) { mvOldPosition = pos; }
	VECTOR GetOldPosition() { return mvOldPosition; }

	void SetRotation(VECTOR rot) { mvRotation = rot; }
	VECTOR GETRotation() { return mvRotation; }

	void SetDeleteFlag(bool flag) { mbDeleteFlag = flag; }
	bool IsDeleteFlag() { return mbDeleteFlag; }

	void SetDrawFlag(bool flag) { mbDrawFlag = flag; } //敵の削除フラグ設定　
	bool IsDrawFlag() { return mbDrawFlag; }          //敵の削除フラグの作成

	//タグ
	void SetTag(Tag3D tag) { mnTag = tag; }
	Tag3D GetTag() { return mnTag; }

protected:
	VECTOR mvPosition;  //座標
	VECTOR mvRotation;   //回転
	VECTOR mvOldPosition;
	CapsuleCollider* mpCapsuleCollider;
	float mfRadius;
private:
	bool mbDeleteFlag;  //削除フラグ
	Tag3D mnTag;   //タグ
	bool mbDrawFlag;//描画フラグ
	float mfCurrentCameraDistance;     // 現在のカメラとの距離
	
	
};