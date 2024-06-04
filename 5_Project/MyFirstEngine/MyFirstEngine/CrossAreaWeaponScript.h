#pragma once
#include "AreaWeaponScript.h"
#include <Queue>

// ������ ���⸦ ���
class CrossAreaWeaponScript : public AreaWeaponScript
{
	static int s_eAreaSoundChannel;
	static int s_eExplosionSoundChannel;
private:
	float m_fInActiveTime = 2.5f; // �� (��ȹ) ������� ��ġ ����
	float m_frameDelay = 0.0f;
	bool flag = true;
	AnimationComponent* m_cRender;
	std::queue<float> m_fQueue;
	float m_fLastQueueTime;
	float m_fStandardTime = 0.0f;
	bool m_bQueueFlag = true;
public:
	CrossAreaWeaponScript(GameObject* pOwner, std::string ObjName);
	
	void ExplosionAnimation(float fixedDeltaTime);
	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime) ;
	virtual void Render() {}; // ������ �Ȼ���� �̹��� �ε� �ؼ�

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src);
	virtual void OnCollisionExit(ColliderComponent* src) {};

	virtual void Reset();
};

