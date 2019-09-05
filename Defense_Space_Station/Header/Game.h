#ifndef GAME_H_
#define GAME_H_

#include "../Header/Player.h"
#include "../Header/Enemy.h"
#include "../Header/Animation.h"

class GAME {
public:
	GAME();
	~GAME();

	void UpdateScene();

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

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_H_
