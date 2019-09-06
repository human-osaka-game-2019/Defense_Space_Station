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


}

void GAME_OVER::Control() {

}

void GAME_OVER::Draw() {

}

void GAME_OVER::Release() {

}

GAME_OVER::GAME_OVER() {

}

GAME_OVER::~GAME_OVER() {

}