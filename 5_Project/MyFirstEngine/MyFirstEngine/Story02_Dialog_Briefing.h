#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"


// ������ ������ �ʿ� �ؾ� �� �� �ش� ���� �Ǹ� �ڵ����� �Ѿ� ����
class Story02_Dialog_Briefing : public GameObject
{
public:
	TypingTextUIScript* myScript;
	Story02_Dialog_Briefing(SceneBase* Scene) : GameObject("Story02_Dialog_Briefing", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Story02_Dialog_BriefingUIScript");

		std::wstring dialogs[11] = 
{
L"..", // �ؽ�Ʈ X

L"..", // �ؽ�Ʈ X
			
L"�ڵ����-SSR. ��� ��, �츮�� ���� ������ ������ �˵����� �� �Լ��� �̵��� �����ߴ�.",

L"���� �ش� �������� ����� ��������, �ı��� ������ �����ȴ�.",

L"���� �ǽð����� �츮 �������� ���� �����ϰ� ������, ��Ȳ�� �ɰ��ϴ�.",

L"�ӹ� ��ǥ�� ��Ȯ�ϴ�. ���� �˵��� ���� ���� ���� �������� �ĺ�, ����, �׸��� �ı��ϴ� ���̴�.",

L"�� �������� ���� �����ϰ� ������, �ٷ��� ���� �̻��ϰ� �뱸�� ������ ������ �����ϰ� �ִ�.",

L"�̵��� ȿ�������� ����ϱ� ���ؼ��� ������ ���ذ� ����� �ʿ��ϴ�.",

L"����, ���� �ݰݿ� ����Ͽ� �׻� �⵿���� �����ϰ� �ֺ� ��Ȳ�� �ֽ��ؾ� �Ѵ�.",

L"���ݱ����� ���� ������ 100%�� ����� ��, �װ� ������ ���̶��� ������ �ʴ´�. �� �ɷ°� ��ܷ¿� �ǽ��� ������ ����.",

L"�׷�, ����� ����. �η� ���Ϳ� ������.",

};

		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story02_Briefing;
	
		myScript->m_eScene_Type = game::SCENE_TYPE::SALLY;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 11);
		myScript->SetRectSizeAndTransform(690, 300, 610, 770);
		myScript->SetFontSize(50);

	}

	virtual ~Story02_Dialog_Briefing() {};
};