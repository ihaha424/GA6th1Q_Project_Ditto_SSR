#pragma once
#include "Object.h"
#include "ColliderManager.h"
#include "ObjectManager.h"

class SceneBase : public Object
{
public:
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

	//��� Scene�� ����� �Ȱ����� ��ӹ޾Ƽ� �� ������ �ֳ�? �; �ϴ� �̷��� ����
	// �ٲܲ��� ��������
	void FixedUpdate(float fixedDeltaTime);
	void Update(float deltaTime);
	void Render();
	void Destroy();

	void Clear();

	
	void AddObject(GameObject* obj, game::OBJECT_TYPE type);
	void EraseObject(game::OBJECT_TYPE type, std::string ObjName);
	
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	SceneBase(std::string m_ObjName);
	virtual ~SceneBase();

protected:
//public:
	//EvnetManager�ȿ� �� ���ɼ��� ����??
	ColliderManager m_ColliderManager;
	ObjectManager m_ObjectManager;

public:
	void AddCollider(ColliderComponent* collider, game::OBJECT_TYPE type = game::OBJECT_TYPE::DEFAULT);

};

