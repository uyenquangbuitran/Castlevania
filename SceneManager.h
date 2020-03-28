#pragma once
#include <Windows.h>
#include <d3dx9.h>

#include "GameObject.h"

#include "Textures.h"
#include "Sprites.h"
#include "Animation.h"

#include "Mario.h"
#include "Goomba.h"
#include "Brick.h"

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20

class SceneManager
{
	static SceneManager * __instance;

public:

	void LoadResource(CGameObject go, int texID, LPCWSTR texFilePath);
	static SceneManager * GetInstance();
};