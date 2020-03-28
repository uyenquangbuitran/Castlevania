#include "SceneManager.h"

void SceneManager::LoadResource(CGameObject go, int texID, LPCWSTR texFilePath)
{
	CTextures * textures = CTextures::GetInstance();

	textures->Add(texID, texFilePath, NULL);

	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
		
	LPDIRECT3DTEXTURE9 tex = textures->Get(texID);

	// big
	sprites->Add(10001, 246, 154, 260, 181, tex);		// idle right

	sprites->Add(10002, 275, 154, 290, 181, tex);		// walk
	sprites->Add(10003, 304, 154, 321, 181, tex);

	sprites->Add(10011, 186, 154, 200, 181, tex);		// idle left
	sprites->Add(10012, 155, 154, 170, 181, tex);		// walk
	sprites->Add(10013, 125, 154, 140, 181, tex);

	sprites->Add(10099, 215, 120, 231, 135, tex);		// die 

	// small
	sprites->Add(10021, 247, 0, 259, 15, tex);			// idle small right
	sprites->Add(10022, 275, 0, 291, 15, tex);			// walk 
	sprites->Add(10023, 306, 0, 320, 15, tex);			// 

	sprites->Add(10031, 187, 0, 198, 15, tex);			// idle small left

	sprites->Add(10032, 155, 0, 170, 15, tex);			// walk
	sprites->Add(10033, 125, 0, 139, 15, tex);			// 

	LPANIMATION ani;

	ani = new CAnimation(100);	// idle big right
	ani->Add(10001);
	animations->Add(400, ani);

	ani = new CAnimation(100);	// idle big left
	ani->Add(10011);
	animations->Add(401, ani);

	ani = new CAnimation(100);	// idle small right
	ani->Add(10021);
	animations->Add(402, ani);

	ani = new CAnimation(100);	// idle small left
	ani->Add(10031);
	animations->Add(403, ani);

	ani = new CAnimation(100);	// walk right big
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(500, ani);

	ani = new CAnimation(100);	// // walk left big
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	animations->Add(501, ani);

	ani = new CAnimation(100);	// walk right small
	ani->Add(10021);
	ani->Add(10022);
	ani->Add(10023);
	animations->Add(502, ani);

	ani = new CAnimation(100);	// walk left small
	ani->Add(10031);
	ani->Add(10032);
	ani->Add(10033);
	animations->Add(503, ani);


	ani = new CAnimation(100);		// Mario die
	ani->Add(10099);
	animations->Add(599, ani);

	mario = new CMario();
	mario->AddAnimation(400);		// idle right big
	mario->AddAnimation(401);		// idle left big
	mario->AddAnimation(402);		// idle right small
	mario->AddAnimation(403);		// idle left small

	mario->AddAnimation(500);		// walk right big
	mario->AddAnimation(501);		// walk left big
	mario->AddAnimation(502);		// walk right small
	mario->AddAnimation(503);		// walk left big

	mario->AddAnimation(599);		// die

	mario->SetPosition(50.0f, 0);
	objects.push_back(mario);
}

SceneManager *SceneManager::GetInstance()
{
	if (__instance == NULL) __instance = new SceneManager();
	return __instance;
}