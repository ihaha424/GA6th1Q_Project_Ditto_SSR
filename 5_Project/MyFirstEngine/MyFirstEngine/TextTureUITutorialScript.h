#pragma once
#include "TextureUIScript.h"

class TextTureUITutorialScript : public TextureUIScript
{
public :
	TextTureUITutorialScript(GameObject* pOwner, std::string ObjName);


	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);
};

