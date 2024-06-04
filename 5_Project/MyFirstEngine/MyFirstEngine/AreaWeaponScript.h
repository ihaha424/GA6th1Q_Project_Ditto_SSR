#pragma once
#include "WeaponScript.h"

//���� ���
class AreaWeaponScript : public WeaponScript 
{
public:
	static Vector3 s_vPlayerPos; // �÷��̾� ��ġ �ľ�

	AreaWeaponScript(GameObject* pOwner, std::string ObjName); // ������
	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime){};
	virtual void Update(float deltaTime) {};
	virtual void Render(){}; // ������ �Ȼ���� �̹��� �ε� �ؼ�

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src) { m_pOwner->SetStatus(game::Status::InActive); };
	virtual void OnCollisionExit(ColliderComponent* src) {};

	virtual void Reset(){}; // �ʱ�ȭ �뵵

private:

protected:
	int m_iAreaWeaponType;  // Ÿ�Կ� ���� �̹��� ���� ���� 0�� ��� ~ ������ ����
	float m_fImageChangeTime; // ���ð��� ������ ����

	float m_fInActiveTime; // ������� Ÿ�� �� ��ȹ���� �����ϱ� ���� ����
//	int m_iRandomPosition;  // �뵵 Ÿ�Կ� ���� ���� ��ġ ���
};

