#include "../Header/Game.h"
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

}

void GAME::Control() {

}

void GAME::Draw() {

}

void GAME::Release() {

}

GAME::GAME() {

}

GAME::~GAME() {

}