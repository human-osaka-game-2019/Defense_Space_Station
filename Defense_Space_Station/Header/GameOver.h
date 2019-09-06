#ifndef GAME_OVER_H_
#define GAME_OVER_H_

#include "../Header/Main.h"
#include "../Header/Vector.h"
#include "../Header/Size.h"

class GAME_OVER {
public:
	GAME_OVER();
	~GAME_OVER();

	void UpdateScene();

private:
	enum STEP {
		LoadStep,
		MainStep,
		ReleaseStep
	};

	STEP step = LoadStep;

	const Vec RetryPos = { 750,550 };
	const Size RetrySize = { 400,100 };
	const Vec GoTitlePos = { 675, 700 };
	const Size GoTitleSize = { 600, 100 };

	const Vec RetryCursorPos = { 700,600 };
	const Vec GoTitleCursorPos = { 600, 750 };

	Vec StarPos;
	const Size StarSize = { 100,100 };
	float StarSpeed;

	const Vec StarUV = { 1400.0f / 2048.0f , 20.0f / 512.0f };
	const Size StarTS = { 120.0f / 2048.0f, 125.0f / 512.0f };

	bool is_titleback;

	void MoveStar();

	void Load();
	void Control();
	void Draw();
	void Release();

};
#endif //GAME_CLEAR_H_
