#pragma once
#include "FontScript.h"

class TypingTextUIScript : public FontScript
{

public:
	TypingTextUIScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime);


	int i_fontCount = 0; // �뵵 �ѱ��ھ� ����ϱ� ���� ���� ī���Ϳ�
	float m_fDelayTime = 0.05f; // ������ Ÿ��
	float m_fMaxDelayTime = m_fDelayTime; // �ƽ� ������ Ÿ��

	bool m_bTextFlag = true;
	bool m_bFullFlag = false;
	
	game::SCENE_TYPE m_eScene_Type; // �� Ÿ�� ��ȯ��
	void SetMyLoadScene(); // ��ȯ �� ���޿�
};

