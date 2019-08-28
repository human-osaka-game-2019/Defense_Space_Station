#ifndef GAME_H_
#define GAME_H_

#include "../Header/Player.h"
#include "../Header/Enemy.h"

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
	Enemy enemy;

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_H_
