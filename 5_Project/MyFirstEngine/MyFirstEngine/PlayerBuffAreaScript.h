#pragma once
#include "AreaWeaponScript.h"

// ������ ���⸦ ���
class PlayerBuffAreaScript : public AreaWeaponScript
{

private:
	

public :

	PlayerBuffAreaScript(GameObject* pOwner, std::string ObjName);
	virtual void Start(); // ���� ������Ʈ
	virtual void FixedUpdate(float fixedDeltaTime);
	virtual void Update(float deltaTime) {};
	virtual void Render() {}; // ������ �Ȼ���� �̹��� �ε� �ؼ�

	virtual void OnCollision(ColliderComponent* src) {};
	virtual void OnCollisionEnter(ColliderComponent* src) {};
	virtual void OnCollisionExit(ColliderComponent* src) {};

	virtual void Reset();
};

