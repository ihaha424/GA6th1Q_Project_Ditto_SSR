#include "GameTime.h"
#include "cmath"


GameTime::GameTime() {}
GameTime::~GameTime() {}
	
void GameTime::InitTime()
{
	QueryPerformanceFrequency(&frequency);	// ���� Ÿ�̸Ӱ� 1�� ���� ������ų�� �ִ� TickCount ��
	QueryPerformanceCounter(&prevCounter);  // �ʱ� TickCount ��
}

void GameTime::UpdateTime()
{
	QueryPerformanceCounter(&currentCounter); // ���� TickCount ��
	deltaTime = static_cast<float>(currentCounter.QuadPart - prevCounter.QuadPart) /
		static_cast<float>(frequency.QuadPart);  // ī�������̸� �ð� �ʴ����� ��ȯ

	prevCounter = currentCounter;
}

float GameTime::GetTimeScale()
{
	return timeScale;
}
void GameTime::SetTimeScale(float n)
{
	if (n < 0)
		return;
	timeScale = n;
}
float GameTime::GetDeltaTime()
{
	return (deltaTime * timeScale);
}
