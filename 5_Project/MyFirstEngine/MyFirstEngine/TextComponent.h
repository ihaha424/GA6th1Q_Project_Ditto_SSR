#pragma once
#include "RenderComponent.h"
#include <vector>
#include <iostream>

class TextComponent :
    public RenderComponent
{
public:
	void FixedUpdate(float fixedDeltaTime) override;
	void Update(float deltaTime) override;
	void Render() override;
	void SetRectSize(float x, float y, float Width, float Height);
	void SetTransform(Vector3 pos);
	void SetTransform(float x, float y, float z = 0);


public:
	std::vector<std::wstring*> m_tString;
	UINT m_uTextIndex;
	UINT m_uColor;
	int m_iFontSize;
	const wchar_t* m_pFontName;

	// �ؽ�Ʈ ��� ���� ����
	RECT m_Rect;

private:
	//Owner�� ��ġ�� ������
	Transform& m_Transform;


public:
	TextComponent(GameObject* pOwner, const std::string& ObjName);
	virtual ~TextComponent();
};

