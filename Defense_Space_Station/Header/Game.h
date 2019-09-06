#ifndef GAME_H_
#define GAME_H_

#include "../Header/Player.h"
#include "../Header/Enemy.h"
#include "../Header/Animation.h"
#include "../Header/UserInterface.h"

class GAME {
public:
	GAME();
	~GAME();

	void UpdateScene();

	UserInterface::UV HpUV = { 20.0f / 2480.0f, 148.0f / 1024.0f, 40.0f / 2480.0f, 40.0f / 1024.0f };

private:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};

	STEP step = LoadStep;

	PLAYER player;
	Enemy enemy[EnemyMax];
	AnimeData data[TextureMax]
	{
		{0.0f, 0.25f, 0, _4F},
		{0.0f, 0.25f, 0, _20F},
		{0.0f, 0.25f, 0, _20F},
		{0.0f, 0.25f, 0, _20F},
		{0.0f, 0.25f, 0, _20F},
		{0.0f, 0.25f, 0, _20F},
		{0.0f, 0.25f, 0, _20F},
		{0.0f, 0.25f, 0, _20F},
	};

	const Size HpSize{ 40,40 };
	Vec HpLeftPos = { 246, 60 };
	Vec HpPos[6];
	const Size HpVarSize{580,100};
	const Vec HpVarPos{ 40, 35 };
	UserInterface::UV HpVarUV = { 320.0f / 2480.0f,150.0f / 1024.0f,575.0f / 2480.0f,100.0f / 1024.0f };
	

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_H_
