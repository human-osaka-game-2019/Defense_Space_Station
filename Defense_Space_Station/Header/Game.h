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
	AnimeData AttackMotion = { 0.0f, 535.0f / 16384.0f , 0, _4F, false, true};
	AnimeData SwoonEnemy = { 0.0f, 100.0f / 1024.0f, 0, _15F, false};
	AnimeData Jump = { 0.0f, 535.0f / 16384.0f, 0, _6F, false };
	AnimeData Ran = { 0.0f, 535.0f / 8192.0f, 0, _8F, false };
	AnimeData Down = { 0.0f, 100.0f / 1024.0f, 0, _8F, false };

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_H_
