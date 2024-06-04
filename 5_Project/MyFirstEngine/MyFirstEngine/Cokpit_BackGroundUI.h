#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class Cokpit_BackGroundUI : public GameObject
{
	TextureUIScript* myScript;

public:
	Cokpit_BackGroundUI(SceneBase* Scene) : GameObject("Cokpit_BackGroundUI", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("Cokpit_BackGroundUI");
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

	
		//���ҽ� ��ġ
		myScript->m_sObjName = L"START_MENU_";
		
		myScript->m_sRoute = L"\\image\\02. START_MENU\\bg_to_cockpit (";
		myScript->SetMyPoldeo(myScript->m_sObjName, myScript->m_sRoute, 9);

		myScript->m_eScene_Type = game::SCENE_TYPE::INTRODUCTION_STORY_NEWS;


		myScript->m_bObjectType = true; // �ִϸ��̼�
		myScript->m_iTextureSize = 9; // �̹��� ����
		myScript->m_fMovieMAXDelayTime = 0.08f; // MAX ��Ÿ

		myScript->m_TexComp->m_iRenderFlag = 1; // ����̸� �� �̰� ���־�� �Ѵ�
	}
};