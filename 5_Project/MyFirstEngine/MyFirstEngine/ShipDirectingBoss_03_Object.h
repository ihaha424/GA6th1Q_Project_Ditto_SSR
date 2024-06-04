#pragma once
#include "GameObject.h"
#include "TextureUIScript.h"

class ShipDirectingBoss_03_Object : public GameObject
{
	TextureUIScript* myScript;

public:
	ShipDirectingBoss_03_Object(SceneBase* Scene) : GameObject("ShipDirectingBoss_03_Object", Scene)
	{
		SetObjType(game::OBJECT_TYPE::UI);
		myScript = CreateComponent<TextureUIScript>("ShipDirectingBoss_03_Object");
		myScript->m_Transform.SetPosition(ScreenWidth / 2, ScreenHeight / 2, 0);

		myScript->m_sObjName = L"ShipDirectingBoss_03_Object";
		myScript->m_sRoute = L"\\TestResource\\meeting_boss3\\meeting_boss3 (";
		myScript->SetMyPoldeo(myScript->m_sObjName, myScript->m_sRoute, 44);

		myScript->m_eScene_Type = game::SCENE_TYPE::STAGE_NORMAL_03;

		myScript->m_bObjectType = true; // �ִϸ��̼�
		myScript->m_iTextureSize = 44; // �̹��� ����
		myScript->m_fMovieMAXDelayTime = 0.08f; // MAX ��Ÿ

		myScript->m_TexComp->m_iRenderFlag = 1; // ����̸� �� �̰� ���־�� �Ѵ�
	}
};