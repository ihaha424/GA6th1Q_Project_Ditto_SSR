#include "BossPageUIScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"

BossPageUIScript::BossPageUIScript(GameObject* pOwner, std::string ObjName)
	:ScriptComponent(pOwner, ObjName), m_TexComp(nullptr)
{
	Start();
}

void BossPageUIScript::Start()
{
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("BossPageUITextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"BossPageUI", L"\\TestResource\\Icon_Sample_0.bmp");
	m_TexComp->m_uExcep = RGB(255, 0, 255);
}

void BossPageUIScript::FixedUpdate(float fixedDeltaTime)
{
	// ���� ���� ü�¿� ���� ��� ���� �����Ͽ� �ϴ� �߰� ��.
}
