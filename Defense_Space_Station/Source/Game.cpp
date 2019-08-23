﻿#include "../Header/Game.h"
#include "../Header/Main.h"

void GAME::UpdateScene() {
	switch (step)
	{
	case GAME::LoadStep:Load();
		break;
	case GAME::MainStep:Control();
		Draw();
		break;
	case GAME::ReleaseStep:Release();
		break;
	default:
		break;
	}
}

void GAME::Load() {
	dx.LoadTexture("../Resource/Player.png", "Player");
	step = MainStep;
}

void GAME::Control() {
	player.Move();

#ifdef _DEBUG
	if (dx.GetKeyState(DIK_ESCAPE) == dx.PUSH) {
		step = ReleaseStep;
	}
#endif
}

void GAME::Draw() {
	dx.Draw(player.GetPos().x, player.GetPos().y, player.GetSize().width, player.GetSize().height, 0.0f, 1.0f, false, "Player");
}

void GAME::Release() {
	dx.ReleaseTexture("Player");
}

GAME::GAME() {

}

GAME::~GAME() {

}