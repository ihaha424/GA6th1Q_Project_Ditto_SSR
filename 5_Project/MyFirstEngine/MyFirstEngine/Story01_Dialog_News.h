#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

class Story01_Dialog_News : public GameObject
{
	
public:
	TypingTextUIScript* myScript;
	Story01_Dialog_News(SceneBase* Scene) : GameObject("Story01_Dialog_News", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Story01_Dialog_NewsUIScript");


std::wstring dialogs[7] = 
		{			
			L" ", // ���� �Ÿ��� �Ҹ�

			L"��� ������ ���մϴ�. ���� ����, �츮�� ���� ������ ���� �˵� �ܰ����� ���������� �������� �����߽��ϴ�.",

			L"�̴� �ݶ��� �Դ밡 ���� ���� �����ϰ� ������ �ǹ��մϴ�.",

			L"��� �ù��� �ִ��� ���� ������ ���Ǽҷ� �̵��Ͻñ� ��ε帳�ϴ�.",

			L"�츮�� ���� ���ձ��� �� ������ �¼� �ο�� ���� ��� ���� ��ġ�� ���ϰ� �ֽ��ϴ�.",

			L"��� ������� ���� �δ뿡 ��� ����� ����������, �츮�� ��� �ý����� ���� �غ� ���¿� �ֽ��ϴ�.	",

			L"�츮�� �� ���⸦ �Բ� �غ��� ���Դϴ�. �ù� �������� ������ ������ �� ��� ������ �߿��մϴ�."

		};

		
		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story01_News;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 7);
		myScript->SetRectSizeAndTransform(800, 500, 550, 730);
		myScript->SetFontSize(50);
		myScript->m_eScene_Type = game::SCENE_TYPE::INTRODUCTION_STORY_BRIEFING;
		
	};
	~Story01_Dialog_News(){};

private:

};
