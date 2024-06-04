#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

// ������ ������ �ʿ� �ؾ� �� �� �ش� ���� �Ǹ� �ڵ����� �Ѿ� ����
class Middle_Story_02_Dialog : public GameObject
{
public:
	TypingTextUIScript* myScript;
	Middle_Story_02_Dialog(SceneBase* Scene) : GameObject("Middle_Story_02_Dialog", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Middle_Story_02_DialogScript");

		std::wstring dialogs[8] =
		{
		L"�̷� ����, �� ������ ���� ������ �����ߴ�. �ý���! ���� �������� ������!",

		L"�� ��ǥ ���� ���Դϴ�...... �м� �Ϸ�. �� ������ ���� �������� �����Դϴ�.",

		L"�� ���, ������ '���� ����' �ӹ� �ϴ��� �����մϴ�. ���� �����͸� ���� ���� �ý��ۿ� ���ε��ϰڽ��ϴ�.",

		L"��� ��Ȳ�̴�, SSR. �� ������ ������ ���� ������ �����ߴ�. ����, �ӹ� ������ �����ϰڴ�.",

		L"���� ��ǥ�� ��� ���� '���� ����'�� �����ϴ� ���̴�. �װ� �� ������ �ٽ��̴�.",

		L"'���� ����'... ���Դϱ�?",

		L"�׷���. SSR, ��� ���� ������ �����϶�. �������� ����.",

		L"�ӹ� Ȯ��. ���� ���� �⵿. ��ǥ ���� ���� �˵�. ����մϴ�!"
		};

		
		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story07_Briefing;

		// ���� ��
		myScript->m_eScene_Type = game::SCENE_TYPE::SHIP_DIRECTING_BOSS_03;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 8);
		myScript->SetRectSizeAndTransform(650, 300, 630, 780);
		myScript->SetFontSize(50);

	}

	virtual ~Middle_Story_02_Dialog() {};
};