#include"Scene.h"
#include"ObjectManager.h"
#include"Master.h"
#include"ColliderManager.h"
#include"GameManager.h"
#include"CowManager.h"
#include"Fever.h"
#include"AnimalManager.h"
Scene::Scene()
{
	//オブジェクトマネージャーの生成
	mpObjectManager = new ObjectManager();
	mpColliderManager = new ColliderManager();
	
}

Scene::~Scene()
{
	
	
	
	if (mpObjectManager != nullptr)
	{
		mpObjectManager->DeleteAll3D();
		delete mpObjectManager;
	}
	if (mpColliderManager != nullptr)
	{
		mpColliderManager->DeleteAllCollider();
		delete mpColliderManager;
		
	}
	if (mpGameManager != nullptr)
	{
		delete mpGameManager;
	}
	if (mpCowManager!=nullptr)
	{
		delete mpCowManager;
	}
	if (mpFever != nullptr)
	{
		delete mpFever;
	}
	if (mpAnimalManager != nullptr)
	{
		delete mpAnimalManager;
	}
	
}
//描画wwwwwwwwwwwwww
void Scene::Draw()
{
	if (mpObjectManager != nullptr)
	{
		mpObjectManager->Draw();
	}
	if (mpColliderManager != nullptr)
	{
		mpColliderManager->Draw();
	}
	if (mpAnimalManager != nullptr)
	{
		mpAnimalManager->Draw();
	}
	
}
//更新
void Scene::Update()
{
	if (mpObjectManager != nullptr)
	{
		
		mpObjectManager->Update();
	}
	if (mpColliderManager != nullptr)
	{
		mpColliderManager->Update();
	}
	if (mpFever != nullptr)
	{
		mpFever->Update();
	}
	if (mpAnimalManager != nullptr)
	{
		mpAnimalManager->Update();
	}
}