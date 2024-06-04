#pragma once
#include <Windows.h>
#include "Resource.h"
#include "Vector3.h"

class Texture :
	public Resource
{
private:
	HDC		m_hDc;
	HBITMAP m_hBit;
	BITMAP	m_tBitInfo;
	Vector3 m_vCutOffsset;

	//�ؽ��Ĵ� ������ recourceManage������ ���� �����ϵ���
private:
	Texture();
	~Texture();

public:
	void Load(std::wstring& _FilePath);
	UINT Width();
	UINT Height();
	UINT CutWidth();
	UINT CutHeight();
	void SetCutOffset(Vector3 cutOffset);
	void SetCutOffset(int x, int y, int z);

	HDC GetDC();

	//�ؽ��Ĵ� ������ recourceManage������ ���� �����ϵ���
	friend class ResourceManager;
};

