#ifndef MAIN_H_
#define MAIN_H_

#include "../../DirectX/DirectX.h"

#ifdef _DEBUG
#include "../Include/Debug/x64/SoundsManager.h"
#else
#include "../Include/Release//x64/SoundsManager.h"
#endif

#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

using DX::DirectX;

extern DirectX dx;
extern SoundLib::SoundsManager soundsManager;
extern RECT WinRect;

enum SCENE {
	Title,
	Game,
	GameOver,
	GameClear
};

extern SCENE g_scene;

#endif //MAIN_H_
