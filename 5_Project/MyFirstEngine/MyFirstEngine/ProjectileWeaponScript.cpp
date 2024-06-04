#include "ProjectileWeaponScript.h"
#include "ResourceManager.h"


// ������: ProjectileWeaponScript�� ���� GameObject�� ��ü �̸����� �ʱ�ȭ
ProjectileWeaponScript::ProjectileWeaponScript(GameObject* pOwner, std::string ObjName)
    : WeaponScript(pOwner, std::move(ObjName)), m_ActivationTime(0.0f), m_IsWarningActive(false), m_cRender(nullptr),
    missileX(2000.0f), missileY(300.0f), missileWidth(50.0f), missileHeight(10.0f)
{
    
}
void ProjectileWeaponScript::Start()
{
    
}
void ProjectileWeaponScript::MoveMissile(float fixedDeltaTime, Vector3 moveDirection)
{
}


void ProjectileWeaponScript::FixedUpdate(float fixedDeltaTime)
{

}
void ProjectileWeaponScript::Activate(Vector3 pos)
{

}
