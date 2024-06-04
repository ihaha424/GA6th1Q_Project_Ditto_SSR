#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Observer.h"


class TutorialButtonUI : public ButtonGameObject
{
public:
	TutorialButtonUI(SceneBase* Scene) : ButtonGameObject("TutorialButtonUI", Scene)
	{
		// �ö��̴� ũ�� ����  ���� �̹��� ũ�⿡ ���� ������ �ʿ�
		m_vButtonScale = Vector3(300, 150, 0);

		// ���� ��ġ ���� �ʿ� ���� ��� �ּ� ������
		m_Transform.SetPosition(320, 500, 0);

		//�̹��� ����
		m_cTexture = CreateComponent<TextureComponent>("TutorialButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"NormalButtonUI", L"\\image\\02. START_MENU\\button_normal_big.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"StartButton2", L"\\image\\02. START_MENU\\button_click_big.bmp");

		m_cTexture->m_uExcep = RGB(255, 0, 255);
		m_cTexture->m_iRenderFlag = 0;

		//��Ʈ ���
		std::wstring* text = new std::wstring(L"TUTORIAL");
		m_cText = CreateComponent<TextComponent>("NumberPrintUITextComponent");
		m_cText->m_pFontName = L"\\Resource\\TestResource\\qwe.ttf";  //��Ʈ ��θ� ã�Ƽ� �ε�
		m_cText->m_uColor = RGB(0, 0, 0); // ��Ʈ ��
		m_cText->m_tString.push_back(text);
		m_cText->SetRectSize(228, 480, 250, 150);
		m_cText->m_iFontSize = 50;
	}

	virtual ~TutorialButtonUI() {};

	void OnClick() override
	{
		// �׽�Ʈ�� ���� �ϴ� ���ܳ���
		Observer::GetInstance()->m_GameFlag = game::SCENE_TYPE::STAGE_TUTORIAL;
		ResourceManager::GetInstance()->PlayMusic(game::eSoundList::UI, 0, game::eSoundChannel::UI);
	}
};