#pragma once

#include "GameObject3D.h"
#include "Vec3.h"
#include "Force.h"
#include "Light.h"
#include "Collider.h"

class Bullet : public GameObject3D
{
private:
	Force m_force;
	Light m_light;
	Collider m_colider;

	GameState* m_pGameState;

	Vec3 m_firePos;
public:
	Bullet(SDL_Surface* surface, SDL_Surface* normalMap, Mesh* mesh);
	~Bullet() {
		GameObject3D::~GameObject3D();
	}
	virtual void Init(GameState* pGameState);
	virtual void Update();
	virtual void Collision(GameObject3D* other);
	virtual void Render();

	void SetDir(Vec3 dir);
};