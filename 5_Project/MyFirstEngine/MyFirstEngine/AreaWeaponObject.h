#pragma once
#include "GameObject.h"
#include "AreaWeaponScript.h"

// ���� ������Ʈ�� ��� �޴´�
class AreaWeaponObject : public GameObject
{

private:
	AreaWeaponScript* m_Script;

public:
	AreaWeaponObject(SceneBase* Scene) : GameObject("WeaponObject", Scene)
	{
		SetObjType(game::OBJECT_TYPE::WEAPON);
		m_Script = CreateComponent<AreaWeaponScript>("AreaWeaponObject");
	}

	virtual void OnCollisionEnter(ColliderComponent* src)
	{
		m_Script->OnCollisionEnter(src);
	}
};

