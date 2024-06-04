#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Observer.h"

class Ending_Button : public ButtonGameObject
{
public:
	Ending_Button(SceneBase* Scene) : ButtonGameObject("Ending_Button", Scene)
	{
		// �ö��̴� ũ�� ����  ���� �̹��� ũ�⿡ ���� ������ �ʿ�
		m_vButtonScale = Vector3(300, 150, 0);
		// ���� ��ġ ���� �ʿ� ���� ��� �ּ� ������
		m_Transform.SetPosition(150, 100, 0);

		//�̹��� ����
		m_cTexture = CreateComponent<TextureComponent>("Ending_Button");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Ending_Button1", L"\\image\\00. UI\\button_normal.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Ending_Button2", L"\\image\\00. UI\\button_click.bmp");


		m_cTexture->m_uExcep = RGB(255, 0, 255);
		m_cTexture->m_iRenderFlag = 0;

		std::wstring* text = new std::wstring(L"CREDIT");
		m_cText = CreateComponent<TextComponent>("NumberPrintUITextComponent");
		m_cText->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //��Ʈ ��θ� ã�Ƽ� �ε�
		m_cText->m_uColor = RGB(0, 0, 0); // ��Ʈ ��
		m_cText->m_tString.push_back(text);
		m_cText->SetRectSize(95, 80, 300, 150);
		m_cText->m_iFontSize = 40;
	}

	virtual ~Ending_Button() {};

	void OnClick() override
	{
		Observer::GetInstance()->m_bHardFlag = false;
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::ENDING;
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::UI, 0, game::eSoundChannel::UI);
	}
};