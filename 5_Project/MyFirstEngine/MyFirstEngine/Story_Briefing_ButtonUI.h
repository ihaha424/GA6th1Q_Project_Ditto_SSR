#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Observer.h"

class Story_Briefing_ButtonUI : public ButtonGameObject
{
public:
	Story_Briefing_ButtonUI(SceneBase* Scene) : ButtonGameObject("Story_Briefing_ButtonUI", Scene)
	{
		//�ö��̴� ũ�� ����
		m_vButtonScale = Vector3(300, 150, 0);
		// ��ġ ���� ���� �ʿ�
		m_Transform.SetPosition(1750.f, 100.f, 0);

		//�̹��� ����
		m_cTexture = CreateComponent<TextureComponent>("Story_Briefing_ButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Story_Briefing_ButtonUI1", L"\\Image\\00. UI\\button_normal.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Story_Briefing_ButtonUI2", L"\\Image\\00. UI\\button_click.bmp");
		
		m_cTexture->m_uExcep = RGB(255, 0, 255);
		m_cTexture->m_iRenderFlag = 0;

		std::wstring* text1 = new std::wstring(L"SKIP");
		m_cText = CreateComponent<TextComponent>("NumberPrintUITextComponent");
		m_cText->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //��Ʈ ��θ� ã�Ƽ� �ε�
		m_cText->m_uColor = RGB(255, 255, 255); // ��Ʈ ��
		m_cText->m_tString.push_back(text1);

		m_cText->SetRectSize(1705, 75, 1750, 100);
		m_cText->m_iFontSize = 50;

	}

	virtual ~Story_Briefing_ButtonUI(){};

	void OnClick() override
	{
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::SALLY;
	}
};