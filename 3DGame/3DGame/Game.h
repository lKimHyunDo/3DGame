#pragma once

#include "defulte.h"
#include "Mesh.h"
#include <vector>

class Camera;
class GameObject;
class CameraController;

using namespace std;

class Game
{
#pragma region Single
private:
	static Game * m_pinst;
public:
	static Game * GetInst() {
		if (m_pinst == 0)
			m_pinst = new Game();
		return m_pinst;
	}
	static void DeleteSingle() {
		if (m_pinst != 0)
			delete m_pinst;
		m_pinst = 0;
	}
#pragma endregion

private:
	SDL_Surface * m_pSurface;
	SDL_Surface* m_pNormal;
	SDL_Surface * m_pSurface2;
	SDL_Surface* m_pNormal2;
	SDL_Surface * m_pSurface3;
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	float fps;
	int startTick;

	char windowTitle[20];
	int screenWidth, screenHeight;

	Mesh cube;
	Mesh teaPot;

	Camera* m_pCamera;

	vector<GameObject*> m_gameObjects;

	GameObject* m_pGameObject;
	GameObject* m_pGameObject2;
	GameObject* m_pGameObject3;
	CameraController* m_pCameraController;

private:
	Game() {}

public:
	virtual ~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);

	void start();
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return m_bRunning; }
	void quit() { m_bRunning = false; }
	
};