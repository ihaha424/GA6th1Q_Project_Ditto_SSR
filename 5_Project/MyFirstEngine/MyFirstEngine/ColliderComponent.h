#pragma once
#include "Component.h"

class ColliderComponent;

class ICollider
{
	virtual void OnCollision(ColliderComponent* src) = 0;
	virtual void OnCollisionEnter(ColliderComponent* src) = 0;
	virtual void OnCollisionExit(ColliderComponent* src) = 0;
};

class ColliderComponent : public Component, ICollider
{
private:
	static UINT s_uStaticID;

public:
	// ICollider��(��) ���� ��ӵ�
	void OnCollision(ColliderComponent* src) override;
	void OnCollisionEnter(ColliderComponent* src) override;
	void OnCollisionExit(ColliderComponent* src) override;

	// Component��(��) ���� ��ӵ�
	void FixedUpdate(float fixedDeltaTime) override;
	void Update(float deltaTime) override;
	void Render() override;

	//Get & Set
	UINT GetColliderID() { return m_uCollisionID; }
	// �����̰� �۾��ϴ� ���� �κ�
	GameObject* GetOwner() const;

public:
	Transform m_Transform;

private:
	UINT	m_uCollisionID;
	UINT	m_uCollisionCount;
	COLORREF	m_RenderColor;

public:
	ColliderComponent(GameObject* pOwner, std::string ObjName);
	~ColliderComponent();

};

