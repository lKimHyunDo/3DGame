#pragma once

#include "GameObject.h"
#include "Vec3.h"
#include "Color.h"
#include "Renderer3D.h"
#include <SDL.h>
#include "Mesh.h"

class Painter;
class Shader;

class GameObject3D : public GameObject
{
protected:
	SDL_Surface* m_pSurface = 0;
	SDL_Surface* m_pNormalMap = 0;
	Mesh* m_pMesh;
	Color m_color = { 255,255,255 };
	Vec3 m_pos = { 0.f,0.f,0.f };
	Vec3 m_scale = { 1.f,1.f,1.f };
	Vec3 m_angle = { 0.f,0.f,0.f };
	Vec3 m_lookAngle = { 0.f,0.f,0.f };

	Painter* m_pPainter;
	Shader* m_pShader;

public:
	GameObject3D(SDL_Surface* surface, SDL_Surface* normalMap, Mesh* mesh);
	GameObject3D(Color color, Mesh* mesh);
	virtual ~GameObject3D() {
		GameObject::~GameObject();
	}

	virtual void Init(GameState* pGameState);
	virtual void Update();
	virtual void Collision(GameObject3D *other);
	virtual void Render();
	virtual void Clean();

	void SetMesh(Mesh* mesh) {
		m_pMesh = mesh;
	}
	void SetSurface(SDL_Surface* surface) {
		m_pSurface = surface;
	}

	void LookAt(Vec3 vec);

	Mesh* GetMesh() {
		return m_pMesh;
	}
	SDL_Surface* GetSurface() {
		return m_pSurface;
	}
	SDL_Surface* GetNormalMap() {
		return m_pNormalMap;
	}
	Vec3 GetScale() {
		return m_scale;
	}

	Painter* GetPainter() {
		return m_pPainter;
	}
	Shader* GetShader() {
		return m_pShader;
	}

	Vec3& RefPos() {
		return m_pos;
	}
	Vec3& RefAngle() {
		return m_angle;
	}
	Vec3& RefLookAtAngle() {
		return m_lookAngle;
	}
	Vec3& RefScale() {
		return m_scale;
	}
	Color& RefColor() {
		return m_color;
	}

};