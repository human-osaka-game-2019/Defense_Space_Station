#include "../Header/GameClear.h"

void GAME_CLEAR::UpdateScene() {
	switch (step)
	{
	case GAME_CLEAR::LoadStep:
		Load();
		break;
	case GAME_CLEAR::MainStep:
		Control();
		Draw();
		break;
	case GAME_CLEAR::ReleaseStep:
		Release();
		break;
	default:
		break;
	}
}

void GAME_CLEAR::Load() {


}

void GAME_CLEAR::Control() {

}

void GAME_CLEAR::Draw() {
	
}

void GAME_CLEAR::Release() {

}

GAME_CLEAR::GAME_CLEAR() {

}

GAME_CLEAR::~GAME_CLEAR() {

}