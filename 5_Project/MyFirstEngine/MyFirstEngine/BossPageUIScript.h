#pragma once
#include "ScriptComponent.h"


class BossPageUIScript : public ScriptComponent
{
public:
	BossPageUIScript(GameObject* pOwner, std::string ObjName);

	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);

	TextureComponent* m_TexComp;

};

