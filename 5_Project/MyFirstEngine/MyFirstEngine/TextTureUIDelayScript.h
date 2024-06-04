#pragma once
#include "TextureUIScript.h"

class TextTureUIDelayScript : public TextureUIScript
{
public:
	TextTureUIDelayScript(GameObject* pOwner, std::string ObjName);

	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime) {};

	int m_iDelayCount = 0; // �뵵 ���° ������ �󸶳� �����̸� �� ���ΰ�
	float m_fOtherMAXDelayTime = 0;

	float m_fStartDelayTime = 0.f;
	bool m_bStartDelayCheck = false;
};

