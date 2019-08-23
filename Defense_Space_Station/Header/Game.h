#ifndef GAME_H_
#define GAME_H_

#include "../Header/Player.h"

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

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_H_
