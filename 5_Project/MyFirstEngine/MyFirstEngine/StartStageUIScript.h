#pragma once
#include "FontScript.h"

class StartStageUIScript : public FontScript
{
public:
	StartStageUIScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);

	void SetAllText(); // �迭 ����

	float MaxdelayTime = 0.f;
	//void DialogReset(int _DialogCount)
	//{
	//	if(m_sDialog != nullptr)
	//		delete[] m_sDialog;
	//	m_sDialog = new std::string[_DialogCount];
	//}

};

