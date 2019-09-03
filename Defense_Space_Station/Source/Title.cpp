#include "../Header/Title.h"
#include "../Header/Main.h"

extern SCENE g_scene;

void TITLE::UpdateScene() {
	switch (step)
	{
	case TITLE::LoadStep:Load();
		break;
	case TITLE::MainStep:Control();
		Draw();
		break;
	case TITLE::ReleaseStep:Release();
		break;
	default:
		break;
	}
}

void TITLE::Load() {
	dx.LoadTexture("Resource/BackGround/TESTtitlebackground.png", "TESTtitle");
	step = MainStep;
}

void TITLE::Control() {
	if (dx.GetKeyState(DIK_SPACE) == dx.PUSH) {
		step = ReleaseStep;
	}
}

void TITLE::Draw() {
	dx.Draw(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, false, "TESTtitle");
}

void TITLE::Release() {
	dx.ReleaseTexture("TESTtitle");

	g_scene = Game;
}

TITLE::TITLE() {

}

TITLE::~TITLE() {

}