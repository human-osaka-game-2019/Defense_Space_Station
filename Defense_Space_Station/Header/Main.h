#ifndef MAIN_H_
#define MAIN_H_

#include "../../DirectX/DirectX.h"

#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

using DX::DirectX;

extern DirectX dx;
extern RECT WinRect;

enum SCENE {
	Title,
	Game,
	GameOver,
	GameClear
};

extern SCENE g_scene;

#endif //MAIN_H_
