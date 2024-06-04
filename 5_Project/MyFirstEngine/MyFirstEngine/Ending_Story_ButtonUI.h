#pragma once
#include "ButtonGameObject.h"
#include "ResourceManager.h"
#include "SceneManager.h"

class Ending_Story_ButtonUI : public ButtonGameObject
{
public:
	Ending_Story_ButtonUI(SceneBase* Scene) : ButtonGameObject("Ending_Story_ButtonUI", Scene)
	{
		//�̹��� ����
		m_cTexture = CreateComponent<TextureComponent>("Ending_Story_ButtonUI");
		m_cTexture->m_tTexture[0] = ResourceManager::GetInstance()->LoadTexture(L"Ending_Story_ButtonUI1", L"\\TestResource\\GuideButton.bmp");
		m_cTexture->m_tTexture[1] = ResourceManager::GetInstance()->LoadTexture(L"Ending_Story_ButtonUI2", L"\\TestResource\\GuideButton2.bmp");
		m_cTexture->m_uExcep = RGB(0, 0, 0);

		//�ö��̴� ũ�� ����
		m_vButtonScale = Vector3(300, 150, 0);

		// ��ġ ���� ���� �ʿ�
		m_Transform.SetPosition(100.f, 200.f, 0);
	}

	virtual ~Ending_Story_ButtonUI() {};

	void OnClick() override
	{
		// ���� ���� �� �Ѿ�� ������ ��
	}
};