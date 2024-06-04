#include "PlayerBuffAreaScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"

PlayerBuffAreaScript::PlayerBuffAreaScript(GameObject* pOwner, std::string ObjName)
	: AreaWeaponScript(pOwner, ObjName)
{
	Start();
}

void PlayerBuffAreaScript::Start()
{
	// �̹��� 
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("PlayerBuffAreaTextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BuffAreaWepon", L"\\TestResource\\Icon_Sample_0.bmp");
	// Ű�� �����ϱ� 

	// m_TexComp->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Monster", L"\\Texture\\Cat_King.bmp");  Ȥ�� ���� ���
	m_TexComp->m_uExcep = RGB(255, 0, 255);
	m_TexComp->m_uRenderIndex = 0;

	// �ݶ��̴� ���� ���� ���� �� �ݶ��̴� ǥ�� ���� �ؾߵ� ���� ��� �ּ� ����
	m_ColComp = m_pOwner->CreateComponent<ColliderComponent>("PlayerBuffAreaColliderComponent");
	m_ColComp->SetStatus(game::Status::Active);
	m_ColComp->m_Transform.SetScale(72.0f, 72.0f, 0);
}

void PlayerBuffAreaScript::FixedUpdate(float fixedDeltaTime)
{

}

void PlayerBuffAreaScript::Reset()
{
	m_fImageChangeTime = 0;
	m_TexComp->m_uRenderIndex = 0;
	m_ColComp->SetStatus(game::Status::InActive);
}


