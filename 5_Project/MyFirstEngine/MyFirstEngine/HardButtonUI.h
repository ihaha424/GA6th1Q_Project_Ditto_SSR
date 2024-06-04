#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Observer.h"

class HardButtonUI : public ButtonGameObject
{
public:
	HardButtonUI(SceneBase* Scene) :ButtonGameObject("HardButtonUI", Scene)
	{
		// �ö��̴� ũ�� ����  ���� �̹��� ũ�⿡ ���� ������ �ʿ�
		m_vButtonScale = Vector3(300, 150, 0);
		// ���� ��ġ ���� �ʿ� ���� ��� �ּ� ������
		m_Transform.SetPosition(1600, 500, 0);

		//�̹��� ����
		m_cTexture = CreateComponent<TextureComponent>("HardButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"NormalButtonUI", L"\\image\\02. START_MENU\\button_normal_big.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"StartButton2", L"\\image\\02. START_MENU\\button_click_big.bmp");

		m_cTexture->m_uExcep = RGB(255, 0, 255);
		m_cTexture->m_iRenderFlag = 0;

		//��Ʈ ���
		std::wstring* text = new std::wstring(L"HARD");
		m_cText = CreateComponent<TextComponent>("NumberPrintUITextComponent");
		m_cText->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //��Ʈ ��θ� ã�Ƽ� �ε�
		m_cText->m_uColor = RGB(255, 0, 0); // ��Ʈ ��
		m_cText->m_tString.push_back(text);
		m_cText->SetRectSize(1550, 480, 250, 150);
		m_cText->m_iFontSize = 50;
	}

	virtual ~HardButtonUI() {};

	void OnClick() override
	{
		Observer::GetInstance()->m_bHardFlag = true;
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::COKPIT;
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::UI, 0, game::eSoundChannel::UI);
	}
};