#pragma once
#include "TextureUIScript.h"

class TextTureUI_Input_Script : public TextureUIScript
{
public :
	TextTureUI_Input_Script(GameObject* pOwner, std::string ObjName);

	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);
	void NextIndex();

	//int m_iInputStop;
};

