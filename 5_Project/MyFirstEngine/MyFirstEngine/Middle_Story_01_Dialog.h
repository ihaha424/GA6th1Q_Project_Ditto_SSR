#pragma once
#include "GameObject.h"
#include "TypingTextUIScript.h"

// ������ ������ �ʿ� �ؾ� �� �� �ش� ���� �Ǹ� �ڵ����� �Ѿ� ����
class Middle_Story_01_Dialog : public GameObject
{
public:
	TypingTextUIScript* myScript;
	Middle_Story_01_Dialog(SceneBase* Scene) : GameObject("Middle_Story_01_Dialog", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TypingTextUIScript>("Middle_Story_01_Dialog");

		std::wstring dialogs[12] =
		{
		L"�� �س´�, �ڵ����-SSR. �ӹ� ��ǥ�� �������� ���ŷ� ��ΰ� �ȵ��� �Ѽ��� ���� �ִ�.", 

		L"���п� �¸����� �� ���� �� �ٰ�����. �η� ���Ϳ� ������.", 

		L"�����մϴ�. �Բ���� � �ӹ��� �ϼ��� �� ���� �Ŷ� �Ͻ��ϴ�. �η� ���Ϳ� ������.",

		L"�׳�����, SSR. �ʴ� ������ ����̾���? ������ ���ؼ��� �󸶳� �˰� �ֳ�?",

		L"���� �����Ŀ��� �ڶ�����, ������ ���� �̾߱�� ���� ������ϴ�.",

		L"�� Ǫ�� �ٴٿ� ���� ����... �������� �� �Ƹ��ٿ��� ���� ������ ���� �;��.",

		L"�׷�, ����. �츮�� ���� Ǫ�� ��. ���� �Ƹ��ٿ�...",

		L"��� �溸! ȭ�� �˵����� ���� ������ �����Ǿ����ϴ�.",

		L"���, ���� ��Ȳ�� ��Ȯ�� �ľ�����. �ý���, �� ������ ���� ��ġ�� �̵� ��θ� ���� �����ϵ���. �츮���� �󸶳� �ð��� ���Ҵ����� �����.",

		L"�м� ���Դϴ�. �� ������ ���� ȭ�� �˵��� ����� �ʾ����� ���� �������� ��� �̵� ���Դϴ�. ���� ���� �ð��� 48�ð� ���Դϴ�.",

		L"�˰ڴ�. SSR! ���ο� �ӹ��� �ϴ��ϰڴ�. �ӹ� ��ǥ�� ���� ������ �����ϰ� �ı��ϴ� ���̴�. �츮 ����� �̷��� �� �տ� �޷��ִ�.",

		L"���� �ɷ��� �ϴ´�, SSR. ��� �ý����� ���� ���� ��ȯ�϶�. �η� ���Ϳ� ������!"
		};

		
		myScript->m_eSoundChannel = game::eSoundChannel::Voice;
		myScript->m_eSoundList = game::eSoundList::STORY_Story05_Briefing;

		// ���� ��
		myScript->m_eScene_Type = game::SCENE_TYPE::SHIP_DIRECTING_BOSS_02;

		myScript->SetMyColor(255, 255, 255);
		myScript->SetMyDialog(dialogs, 12);
		myScript->SetRectSizeAndTransform(650, 300, 630, 780);
		myScript->SetFontSize(50);

	}

	virtual ~Middle_Story_01_Dialog() {};
};