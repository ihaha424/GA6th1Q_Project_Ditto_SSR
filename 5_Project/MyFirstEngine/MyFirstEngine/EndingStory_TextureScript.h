#pragma once
#include "TextureUIScript.h"

class FadeInFadeOutObject;

class EndingStory_TextureScript : public TextureUIScript
{
public:
	EndingStory_TextureScript(GameObject* pOwner, std::string ObjName);


	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);

	bool m_bBriefing = false;
	bool m_bFadeinFadeoutCooltime = false;
	bool m_bExplosion = false;

	FadeInFadeOutObject* fadeInFadeOutObject;

	~EndingStory_TextureScript();
};

