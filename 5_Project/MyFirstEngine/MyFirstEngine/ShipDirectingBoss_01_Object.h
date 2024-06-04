#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class ShipDirectingBoss_01_Object : public GameObject
{
	TextureUIScript* myScript;

public:
	ShipDirectingBoss_01_Object(SceneBase* Scene) :GameObject("ShipDirectingBoss_01_Object", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("ShipDirectingBoss_01_Object");
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

		myScript->m_sObjName = L"ShipDirectingBoss_01_Object";
		myScript->m_sRoute = L"\\TestResource\\meeting_boss1\\meeting_boss1 (";
		myScript->SetMyPoldeo(myScript->m_sObjName, myScript->m_sRoute, 46);

		myScript->m_eScene_Type = game::SCENE_TYPE::STAGE_NORMAL_01;

		myScript->m_bObjectType = true; // �ִϸ��̼�
		myScript->m_iTextureSize = 46; // �̹��� ����
		myScript->m_fMovieMAXDelayTime = 0.08f; // MAX ��Ÿ

		myScript->m_TexComp->m_iRenderFlag = 1; // ����̸� �� �̰� ���־�� �Ѵ�
	}

	
};