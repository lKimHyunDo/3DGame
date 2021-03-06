#pragma once

#include "Vec3.h"

class GameObject3D;

class Force
{
private:
	GameObject3D* m_pGameObject;

	Vec3 m_velocity = { 0.f,0.f,0.f };
	Vec3 m_acceleration = { 0.f,0.f,0.f };

public:
	Force(GameObject3D* gameObject);

	void AddForce(Vec3 force);

	void Update();

	Vec3& RefVelocity() {
		return m_velocity;
	}
	Vec3& RefForce() {
		return m_acceleration;
	}
};