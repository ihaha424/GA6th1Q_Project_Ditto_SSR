#pragma once

#include "Vector3.h"

class Transform
{
public:
	Vector3 Position;
	//Vector3 _offsetPosition;
	//����(0~360)
	Vector3 Rotation;	//�⺻ ����(1,0,0) ->
	Vector3 Scale;

public:
	Transform(void);
	Transform(const Transform& src);

	~Transform(void);

	Transform& operator=(const Transform& rhs);

	void SetPosition(const float x, const float y, const float z);
	void SetPosition(const Vector3& v);
	Vector3 GetPosition();

	//void SetOffsetPosition(const float x, const float y, const float z);
	//void SetOffsetPosition(const Vector3& v);
	//Vector3 GetOffsetPosition();

	void SetRotation(const float x, const float y, const float z);
	void SetRotation(const Vector3& v);
	Vector3 GetRotation();
	//���� ����
	Vector3 GetRotationVector();
	Vector3 GetRotationVector(Vector3 v);



	void SetScale(const float x, const float y, const float z);
	void SetScale(const Vector3& v);
	Vector3 GetScale();

};