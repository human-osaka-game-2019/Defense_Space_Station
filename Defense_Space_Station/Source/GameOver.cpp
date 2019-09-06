#include "../Header/GameOver.h"

void GAME_OVER::UpdateScene() {
	switch (step)
	{
	case GAME_OVER::LoadStep:
		Load();
		break;
	case GAME_OVER::MainStep:
		Control();
		Draw();
		break;
	case GAME_OVER::ReleaseStep:
		Release();
		break;
	default:
		break;
	}
}

void GAME_OVER::Load() {
	dx.LoadTexture("Resource/BackGround/GameOverBack.png", "BackGround");
	dx.LoadTexture("Resource/UI/ResultUI.png", "ResultUI");

	step = MainStep;
}

void GAME_OVER::Control() {
	if (dx.GetKeyState(DIK_W) == dx.PUSH) {
		is_titleback = !is_titleback;
	}
	else if (dx.GetKeyState(DIK_S) == dx.PUSH) {
		is_titleback = !is_titleback;
	}

	MoveStar();

	if (dx.GetKeyState(DIK_RETURN) == dx.PUSH) {
		step = ReleaseStep;
	}
}

void GAME_OVER::Draw() {
	dx.Draw(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, false, "BackGround");
	dx.DrawEx(RetryPos.x, RetryPos.y, 0.0f, RetrySize.width, RetrySize.height, 0.0f, 1.0f, false, "ResultUI", 20.0f / 2048.0f, 20.0f / 512.0f, 500.0f / 2048.0f, 160.0f / 512.0f);
	dx.DrawEx(GoTitlePos.x, GoTitlePos.y, 0.0f, GoTitleSize.width, GoTitleSize.height, 0.0f, 1.0f, false, "ResultUI", 550.0f / 2048.0f, 20.0f / 512.0f, 830.0f / 2048.0f, 160.0f / 512.0f);
	dx.DrawCenterEx(StarPos.x, StarPos.y, 0.0f, StarSize.width, StarSize.height, 0.0f, 1.0f, false, "ResultUI", StarUV.x, StarUV.y, StarTS.width, StarTS.height);
}

void GAME_OVER::Release() {
	dx.ReleaseTexture("ResultUI");
	dx.ReleaseTexture("BackGround");
	if (is_titleback) {
		g_scene = Title;
	}
	else {
		g_scene = Game;
	}
}

void GAME_OVER::MoveStar() {
	if (is_titleback) {
		if (StarPos.x >= GoTitleCursorPos.x && StarPos.y <= GoTitleCursorPos.y) {
			StarPos.x -= StarSpeed;
			StarPos.y += StarSpeed;
		}
		else if (StarPos.y <= GoTitleCursorPos.y) {
			StarPos.y += StarSpeed;
		}
		else if (StarPos.x >= GoTitleCursorPos.x) {
			StarPos.x -= StarSpeed;
		}
	}
	else {
		if (StarPos.x <= RetryCursorPos.x && StarPos.y >= RetryCursorPos.y) {
			StarPos.x += StarSpeed;
			StarPos.y -= StarSpeed;
		}
		else if (StarPos.y >= RetryCursorPos.y) {
			StarPos.y -= StarSpeed;
		}
		else if (StarPos.x <= RetryCursorPos.x) {
			StarPos.x += StarSpeed;
		}
	}
}

GAME_OVER::GAME_OVER():is_titleback(false), StarSpeed(2.0f) {
	StarPos = RetryCursorPos;
}

GAME_OVER::~GAME_OVER() {

}