#include "NumberPrintUIScript.h"
#include "SceneBase.h"
#include "ResourceManager.h"
#include "FontScript.h"

NumberPrintUIScript::NumberPrintUIScript(GameObject* pOwner, std::string ObjName)
	:FontScript(pOwner, ObjName)
{
	Start();
}

void NumberPrintUIScript::Start()
{
	// ���ڰ� �ȳ��ͼ� ��ġ�� ������ Ȯ�ο�
	m_TexComp = m_pOwner->CreateComponent<TextureComponent>("StartStageUITextureComponent");
	m_TexComp->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"PlayerShipUI", L"\\TestResource\\Ship_Player_0.bmp");

	m_TextComp = m_pOwner->CreateComponent<TextComponent>("NumberPrintUITextComponent");
	m_TextComp->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //��Ʈ ��θ� ã�Ƽ� �ε�
	m_TextComp->m_uColor = RGB(0, 0, 0); // ��Ʈ ��
	m_TextComp->m_tString.push_back(&m_sNumber);  // �̰� ���־���� ��µȴ� �� �ض�
}

void NumberPrintUIScript::FixedUpdate(float fixedDeltaTime)
{
	// ���⸦ �����ؼ� ó�� �ϸ� ��.
	m_iNumber += 1; // static���� �� �޾Ƽ� �����ؼ� ����ϸ� ��
	m_sNumber = std::to_wstring(static_cast<int>(m_iNumber)) + L"%";
}



