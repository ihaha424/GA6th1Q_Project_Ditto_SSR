#pragma once
#include "FontScript.h"
// ���� ���� ��Ʈ ��ũ��Ʈ ��� �ް�

class NumberPrintUIScript : public FontScript
{
public:
	NumberPrintUIScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);


	int m_iNumber; // ���� �뵵 ���⿡�� static���� �� �޾Ƽ� �����ؼ� ����ϸ� ��
	std::wstring m_sNumber;

};


