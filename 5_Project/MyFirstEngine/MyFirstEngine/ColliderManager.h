#pragma once

#include <Windows.h>
#include <vector>
#include <unordered_map>
#include "Define.h"

class Collider;
class ColliderComponent;

class ColliderManager
{
public:
	void AddColliderObject(ColliderComponent* collider, game::OBJECT_TYPE type);
	void CheckGroup(game::OBJECT_TYPE lhs, game::OBJECT_TYPE rhs);
	void ResetGroup();


public:
	void Initialize();
	void FixedUpdate();
	void Destroy();
	void Clear();

public:
	ColliderManager();
	~ColliderManager();

private:
	std::vector<ColliderComponent*>	m_vColliderArr[(UINT)game::OBJECT_TYPE::END];
	UINT					m_uCheckArr[(UINT)game::OBJECT_TYPE::END];
	//���� �������� �浹 ����
	//�̰��� �־���� ���Դ��� �浹������ �������� �� �� �ִ�.
	//������ ���̵� ���� �ΰ��� �������� Hash�� ���Ͽ� ���� ����
	//UNION�� ���� ���̵� 1, ���̵� 2�� �Ѱ��� ������ �� �� ����
	std::unordered_map<long long, bool> m_mCollisionInfo;

	union ColliderID
	{
		struct {
			UINT LeftID;
			UINT RightID;
		};
		LONGLONG ID;
	};

private:
	void CollisionCheck(game::OBJECT_TYPE lhs, game::OBJECT_TYPE rhs);
	bool IsCollision(ColliderComponent* lhs, ColliderComponent* rhs);

};